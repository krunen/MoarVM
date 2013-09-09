#define MVM_REPR_ID_CPointer 25
#define MVM_REPR_ID_CScalar  26
#define MVM_REPR_ID_CArray   27
#define MVM_REPR_ID_CStruct  28
#define MVM_REPR_ID_CUnion   29

typedef struct MVMCPointer MVMCPointer;
typedef struct MVMCPointerBody MVMCPointerBody;

typedef struct MVMCScalar MVMCScalar;
typedef struct MVMCScalarBody MVMCScalarBody;

typedef struct MVMCArray MVMCArray;
typedef struct MVMCArrayBody MVMCArrayBody;

typedef struct MVMCStruct MVMCStruct;
typedef struct MVMCStructBody MVMCStructBody;

typedef struct MVMCUnion MVMCUnion;
typedef struct MVMCUnionBody MVMCUnionBody;

enum {
    MVM_CSCALAR_VOID    =  0,
    MVM_CSCALAR_CHAR    =  1,
    MVM_CSCALAR_UCHAR   =  2,
    MVM_CSCALAR_SHORT   =  3,
    MVM_CSCALAR_USHORT  =  4,
    MVM_CSCALAR_INT     =  5,
    MVM_CSCALAR_UINT    =  6,
    MVM_CSCALAR_LONG    =  7,
    MVM_CSCALAR_ULONG   =  8,
    MVM_CSCALAR_LLONG   =  9,
    MVM_CSCALAR_ULLONG  = 10,
    MVM_CSCALAR_INT8    = 11,
    MVM_CSCALAR_UINT8   = 12,
    MVM_CSCALAR_INT16   = 13,
    MVM_CSCALAR_UINT16  = 14,
    MVM_CSCALAR_INT32   = 15,
    MVM_CSCALAR_UINT32  = 16,
    MVM_CSCALAR_INT64   = 17,
    MVM_CSCALAR_UINT64  = 18,
    MVM_CSCALAR_INTPTR  = 19,
    MVM_CSCALAR_UINTPTR = 20,
    MVM_CSCALAR_INTMAX  = 21,
    MVM_CSCALAR_UINTMAX = 22,
    MVM_CSCALAR_FLOAT   = 23,
    MVM_CSCALAR_DOUBLE  = 24,
    MVM_CSCALAR_LDOUBLE = 25,
    MVM_CSCALAR_PTR     = 26,
    MVM_CSCALAR_FPTR    = 27,
};

struct MVMCPointerBody {
    void *ptr;
};

struct MVMCPointer {
    MVMObject common;
    MVMCPointerBody body;
};

struct MVMCScalarBody {
    void *ptr;
    MVMuint8 is_obj;
};

struct MVMCScalar {
    MVMObject common;
    MVMCScalarBody body;
};

struct MVMCArrayBody {
    void *ptr;
    MVMuint8 *obj_map;
    MVMuint64 size;
};

struct MVMCArray {
    MVMObject common;
    MVMCArrayBody body;
};

struct MVMCStructBody {
    void *ptr;
    MVMuint8 *obj_map;
};

struct MVMCStruct {
    MVMObject common;
    MVMCStructBody body;
};

struct MVMCUnionBody {
    void *ptr;
    MVMuint8 *obj_map;
};

struct MVMCUnion {
    MVMObject common;
    MVMCUnionBody body;
};

MVMObject * MVM_native_ptrcast(MVMThreadContext *tc, MVMObject *type_obj,
        MVMObject *ptr_obj, MVMint64 offset);
