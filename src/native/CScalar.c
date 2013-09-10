#include "moarvm.h"

typedef struct {
    MVMuint16 type;
} CScalarSpec;

static const CScalarSpec SPEC_VOID    = { MVM_CSCALAR_VOID };
static const CScalarSpec SPEC_CHAR    = { MVM_CSCALAR_CHAR };
static const CScalarSpec SPEC_UCHAR   = { MVM_CSCALAR_UCHAR };
static const CScalarSpec SPEC_SHORT   = { MVM_CSCALAR_SHORT };
static const CScalarSpec SPEC_USHORT  = { MVM_CSCALAR_USHORT };
static const CScalarSpec SPEC_INT     = { MVM_CSCALAR_INT };
static const CScalarSpec SPEC_UINT    = { MVM_CSCALAR_UINT };
static const CScalarSpec SPEC_LONG    = { MVM_CSCALAR_LONG };
static const CScalarSpec SPEC_ULONG   = { MVM_CSCALAR_ULONG };
static const CScalarSpec SPEC_LLONG   = { MVM_CSCALAR_LLONG };
static const CScalarSpec SPEC_ULLONG  = { MVM_CSCALAR_ULLONG };
static const CScalarSpec SPEC_INT8    = { MVM_CSCALAR_INT8 };
static const CScalarSpec SPEC_UINT8   = { MVM_CSCALAR_UINT8 };
static const CScalarSpec SPEC_INT16   = { MVM_CSCALAR_INT16 };
static const CScalarSpec SPEC_UINT16  = { MVM_CSCALAR_UINT16 };
static const CScalarSpec SPEC_INT32   = { MVM_CSCALAR_INT32 };
static const CScalarSpec SPEC_UINT32  = { MVM_CSCALAR_UINT32 };
static const CScalarSpec SPEC_INT64   = { MVM_CSCALAR_INT64 };
static const CScalarSpec SPEC_UINT64  = { MVM_CSCALAR_UINT64 };
static const CScalarSpec SPEC_INTPTR  = { MVM_CSCALAR_INTPTR };
static const CScalarSpec SPEC_UINTPTR = { MVM_CSCALAR_UINTPTR };
static const CScalarSpec SPEC_INTMAX  = { MVM_CSCALAR_INTMAX };
static const CScalarSpec SPEC_UINTMAX = { MVM_CSCALAR_UINTMAX };
static const CScalarSpec SPEC_FLOAT   = { MVM_CSCALAR_FLOAT };
static const CScalarSpec SPEC_DOUBLE  = { MVM_CSCALAR_DOUBLE };
static const CScalarSpec SPEC_LDOUBLE = { MVM_CSCALAR_LDOUBLE };
static const CScalarSpec SPEC_PTR     = { MVM_CSCALAR_PTR };
static const CScalarSpec SPEC_FPTR    = { MVM_CSCALAR_FPTR };

static const char * const CNAMES[] = {
    "void",
    "signed char",
    "unsigned char",
    "short",
    "unsigned short",
    "int",
    "unsigned int",
    "long",
    "unsigned long",
    "long long",
    "unsigned long long",
    "int8_t",
    "uint8_t",
    "int16_t",
    "uint16_t",
    "int32_t",
    "uint32_t",
    "int64_t",
    "uint64_t",
    "intptr_t",
    "uintptr_t",
    "intmax_t",
    "uintmax_t",
    "float",
    "double",
    "long double",
    "void *",
    "void (*)(void)",
};

static MVMREPROps this_repr;

MVMREPROps * MVMCScalar_initialize(MVMThreadContext *tc) {
    return &this_repr;
}
