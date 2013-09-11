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

struct MVMCScalarSpec {
    MVMuint64 size;
    MVMuint16 align;
    MVMuint16 id;
    const char *name;
};

struct MVMCBlobBody {
    char *storage;
    MVMuint64 size;
    MVMuint8 *refmap;
};

struct MVMCBlob {
    MVMObject common;
    MVMCBlobBody body;
};

struct MVMCPointerBody {
    void *cobj;
    MVMCBlob *blob;
};

struct MVMCPointer {
    MVMObject common;
    MVMCPointerBody body;
};

typedef struct {
    void *cobj;
    MVMCBlob *blob;
} MVMCScalarBody_;

union MVMCScalarBody {
    MVMCPointerBody POINTER;
    MVMCScalarBody_ SCALAR;
};

typedef struct {
    MVMObject common;
    MVMCScalarBody body;    
} MVMCScalar_;

union MVMCScalar {
    MVMCPointer POINTER;
    MVMCScalar_ SCALAR;
};

typedef struct {
    void *cobj;
    MVMCBlob *blob;
    MVMuint64 size;
} MVMCArrayBody_;

union MVMCArrayBody {
    MVMCPointerBody POINTER;
    MVMCArrayBody_  ARRAY;
};

typedef struct {
    MVMObject common;
    MVMCArrayBody body;
} MVMCArray_;

union MVMCArray {
    MVMCPointer POINTER;
    MVMCArray_  ARRAY;
};

typedef struct {
    void *cobj;
    MVMCBlob *blob;
} MVMCStructBody_;

union MVMCStructBody {
    MVMCPointerBody POINTER;
    MVMCStructBody_ STRUCT;
};

typedef struct {
    MVMObject common;
    MVMCStructBody body;
} MVMCStruct_;

union MVMCStruct {
    MVMCPointer POINTER;
    MVMCStruct_ STRUCT;
};

typedef struct {
    void *cobj;
    MVMCBlob *blob;
} MVMCUnionBody_;

union MVMCUnionBody {
    MVMCPointerBody POINTER;
    MVMCUnionBody_  UNION;
};

typedef struct {
    MVMObject common;
    MVMCUnionBody body;
} MVMCUnion_;

union MVMCUnion {
    MVMCPointer POINTER;
    MVMCUnion_  UNION;
};

typedef struct {
    void *cobj;
    MVMCBlob *blob;
    MVMCArray *flexibles;
} MVMCFlexStructBody_;

union MVMCFlexStructBody {
    MVMCPointerBody     POINTER;
    MVMCStructBody_     STRUCT;
    MVMCFlexStructBody_ FLEX_STRUCT;
};

typedef struct {
    MVMObject common;
    MVMCFlexStructBody body;
} MVMCFlexStruct_;

union MVMCFlexStruct {
    MVMCPointer     POINTER;
    MVMCStruct_     STRUCT;
    MVMCFlexStruct_ FLEX_STRUCT;
};

extern MVMREPROps MVM_REPR_CPointer;
extern MVMREPROps MVM_REPR_CScalar;

MVMREPROps * MVMCBlob_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCPointer_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCScalar_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCArray_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCStruct_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCUnion_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCFlexStruct_initialize(MVMThreadContext *tc);

const MVMCScalarSpec * MVM_native_get_scalar_spec(MVMThreadContext *tc,
        MVMint64 id);
