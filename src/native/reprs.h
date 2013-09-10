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

struct MVMCBlob {
    MVMObject common;
};

struct MVMCBlobSpec {
    MVMObject *ctype;
    MVMuint64  size;
    MVMuint16  align;
};

struct MVMCPointerBody {
    void *cobj;
};

struct MVMCPointer {
    MVMObject common;
    MVMCPointerBody body;
};

struct MVMCScalarBody {
    void *cobj;
    MVMuint32 flags;
};

struct MVMCScalar {
    MVMObject common;
    MVMCScalarBody body;
};

struct MVMCArrayBody {
    void *cobj;
    MVMuint32 flags;
    MVMuint8 *ref_map;
    MVMuint64 size;
};

struct MVMCArray {
    MVMObject common;
    MVMCArrayBody body;
};

struct MVMCStructBody {
    void *cobj;
    MVMuint32 flags;
    MVMuint8 *ref_map;
};

struct MVMCStruct {
    MVMObject common;
    MVMCStructBody body;
};

struct MVMCUnionBody {
    void *cobj;
    MVMuint32 flags;
    MVMuint8 *ref_map;
};

struct MVMCUnion {
    MVMObject common;
    MVMCUnionBody body;
};

struct MVMCFlexibleStructBody {
    void *cobj;
    MVMuint32 flags;
    MVMuint8 *ref_map;
    MVMuint64 flexible_size;
};

struct MVMCFlexibleStruct {
    MVMObject common;
    MVMCFlexibleStructBody body;
};

MVMREPROps * MVMCBlob_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCPointer_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCScalar_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCArray_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCStruct_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCUnion_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCFlexibleStruct_initialize(MVMThreadContext *tc);
