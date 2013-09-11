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

union MVMCScalarBody {
    MVMCPointerBody parent_body;
    struct {
        void *cobj;
        MVMCBlob *blob;
    };
};

union MVMCScalar {
    MVMCPointer parent;
    struct {
        MVMObject common;
        MVMCScalarBody body;
    };
};

union MVMCArrayBody {
    MVMCPointerBody parent_body;
    struct {
        void *cobj;
        MVMCBlob *blob;
        MVMuint64 size;
    };
};

union MVMCArray {
    MVMCPointer parent;
    struct {
        MVMObject common;
        MVMCArrayBody body;
    };
};

union MVMCStructBody {
    MVMCPointerBody parent_body;
    struct {
        void *cobj;
        MVMCBlob *blob;
    };
};

union MVMCStruct {
    MVMCPointer parent;
    struct {
        MVMObject common;
        MVMCStructBody body;
    };
};

union MVMCUnionBody {
    MVMCPointerBody parent_body;
    struct {
        void *cobj;
        MVMCBlob *blob;
    };
};

union MVMCUnion {
    MVMCPointer parent;
    struct {
        MVMObject common;
        MVMCUnionBody body;
    };
};

union MVMCFlexibleStructBody {
    MVMCStructBody parent_body;
    struct {
        void *cobj;
        MVMCBlob *blob;
        MVMCArray *flexibles;
    };
};

union MVMCFlexibleStruct {
    MVMCStruct parent;
    struct {
        MVMObject common;
        MVMCFlexibleStructBody body;
    };
};

extern MVMREPROps MVM_REPR_CPointer;

MVMREPROps * MVMCBlob_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCPointer_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCScalar_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCArray_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCStruct_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCUnion_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCFlexibleStruct_initialize(MVMThreadContext *tc);
