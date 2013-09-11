#include <stdlib.h>
#include <stdarg.h>

/* Configuration. */
#include "gen/config.h"

/* Standard integer types. */
#include <platform/inttypes.h>

/* stuff for uthash */
#define uthash_fatal(msg) MVM_exception_throw_adhoc(tc, "internal hash error: " msg)

#include <uthash.h>

/* libuv
 * must precede atomic_ops.h so we get the ordering of Winapi headers right
 */
#include <uv.h>

/* libatomic_ops */
#include <atomic_ops.h>

/* forward declarations */
#include "types.h"

/* Sized types. */
typedef int8_t   MVMint8;
typedef uint8_t  MVMuint8;
typedef int16_t  MVMint16;
typedef uint16_t MVMuint16;
typedef int32_t  MVMint32;
typedef uint32_t MVMuint32;
typedef int64_t  MVMint64;
typedef uint64_t MVMuint64;
typedef float    MVMnum32;
typedef double   MVMnum64;

#if defined MVM_BUILD_SHARED
#  define MVM_PUBLIC  MVM_DLL_EXPORT
#  define MVM_PRIVATE MVM_DLL_LOCAL
#elif defined MVM_SHARED
#  define MVM_PUBLIC  MVM_DLL_IMPORT
#  define MVM_PRIVATE MVM_DLL_LOCAL
#else
#  define MVM_PUBLIC
#  define MVM_PRIVATE
#endif

/* Number of scalar native C types */
enum { MVM_CSCALAR_TYPE_COUNT = 28 };

/* Headers for APIs for various other data structures and APIs. */
#include "6model/6model.h"
#include "core/threadcontext.h"
#include "core/instance.h"
#include "core/interp.h"
#include "core/args.h"
#include "core/exceptions.h"
#include "core/frame.h"
#include "core/validation.h"
#include "core/compunit.h"
#include "core/bytecode.h"
#include "core/bytecodedump.h"
#include "core/ops.h"
#include "core/threads.h"
#include "core/hll.h"
#include "core/loadbytecode.h"
#include "core/coerce.h"
#include "6model/reprs.h"
#include "6model/reprconv.h"
#include "6model/bootstrap.h"
#include "6model/containers.h"
#include "6model/sc.h"
#include "6model/serialization.h"
#include "gc/allocation.h"
#include "gc/worklist.h"
#include "gc/collect.h"
#include "gc/orchestrate.h"
#include "gc/gen2.h"
#include "gc/roots.h"
#include "gc/wb.h"
#include "strings/ascii.h"
#include "strings/utf8.h"
#include "strings/ops.h"
#include "strings/unicode_gen.h"
#include "strings/unicode.h"
#include "strings/latin1.h"
#include "io/fileops.h"
#include "io/socketops.h"
#include "io/dirops.h"
#include "io/procops.h"
#include "math/bigintops.h"
#include "mast/driver.h"

/* Top level VM API functions. */
MVM_PUBLIC MVMInstance * MVM_vm_create_instance(void);
MVM_PUBLIC void MVM_vm_run_file(MVMInstance *instance, const char *filename);
MVM_PUBLIC void MVM_vm_dump_file(MVMInstance *instance, const char *filename);
MVM_PUBLIC void MVM_vm_destroy_instance(MVMInstance *instance);

/* Returns original. Use only on AO_t-sized values (including pointers). */
#define MVM_incr(addr) AO_fetch_and_add1_full((volatile AO_t *)(addr))
#define MVM_decr(addr) AO_fetch_and_sub1_full((volatile AO_t *)(addr))
#define MVM_add(addr, add) AO_fetch_and_add_full((volatile AO_t *)(addr), (AO_t)(add))

/* Returns non-zero for success. Use for both AO_t numbers and pointers. */
#define MVM_trycas(addr, old, new) AO_compare_and_swap_full((volatile AO_t *)(addr), (AO_t)(old), (AO_t)(new))

/* Returns the old value dereferenced at addr. */
#define MVM_cas(addr, old, new) AO_fetch_compare_and_swap_full((addr), (old), (new))

/* Returns the old pointer value dereferenced at addr. Provided for a tiny bit of type safety. */
#define MVM_casptr(addr, old, new) ((void *)MVM_cas((AO_t *)(addr), (AO_t)(old), (AO_t)(new)))

/* Full memory barrier. */
#define MVM_barrier() AO_nop_full()

/* Convenience shortcut for use in gc_free routines. */
#define MVM_checked_free_null(addr) do { \
    if ((addr)) { \
        free((addr)); \
        (addr) = NULL; \
    } \
} while (0)

/* Need to use these to assign to or read from any memory locations on
 * which the other atomic operation macros are used... */
#define MVM_store(addr, new) AO_store_full((volatile AO_t *)(addr), (AO_t)(new))
#define MVM_load(addr) AO_load_full((volatile AO_t *)(addr))
