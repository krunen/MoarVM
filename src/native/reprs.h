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
    /* size needs to come first as that's the expected
     * REPR_data for any pointer type
     */
    MVMuint64 size;
    MVMuint16 align;
    MVMuint16 can_box;
    MVMuint16 id;
    const char *cname;
    MVMObject * (*fetch)(MVMThreadContext *, void *);
    void (*store)(MVMThreadContext *, void *, MVMObject *);
};

/* VMBlob */

struct MVMBlobBody {
    char *storage;
    MVMuint64  size;
    MVMuint64 *refmap;
};

struct MVMBlob {
    MVMObject common;
    MVMBlobBody body;
};

/* VMPtr */

struct MVMPtrBody {
    void *cobj;
    MVMBlob *blob;
};

struct MVMPtr {
    MVMObject common;
    MVMPtrBody body;
};

/* CScalar */

typedef struct {
    void *cobj;
    MVMBlob *blob;
} MVMCScalarBody_;

union MVMCScalarBody {
    MVMPtrBody VMPTR;
    MVMCScalarBody_ SCALAR;
};

typedef struct {
    MVMObject common;
    MVMCScalarBody body;
} MVMCScalar_;

union MVMCScalar {
    MVMPtr      VMPTR;
    MVMCScalar_ SCALAR;
};

/* CPointer */

typedef struct {
    void *cobj;
    MVMBlob *blob;
    MVMObject *type;
} MVMCPointerBody_;

union MVMCPointerBody {
    MVMPtrBody       VMPTR;
    MVMCScalarBody_  SCALAR;
    MVMCPointerBody_ POINTER;
};

typedef struct {
    MVMObject common;
    MVMCPointerBody body;
} MVMCPointer_;

union MVMCPointer {
    MVMPtr       VMPTR;
    MVMCScalar_  SCALAR;
    MVMCPointer_ POINTER;
};

/* CArray */

typedef struct {
    void *cobj;
    MVMBlob *blob;
    MVMuint64 size;
} MVMCArrayBody_;

union MVMCArrayBody {
    MVMPtrBody VMPTR;
    MVMCArrayBody_  ARRAY;
};

typedef struct {
    MVMObject common;
    MVMCArrayBody body;
} MVMCArray_;

union MVMCArray {
    MVMPtr     VMPTR;
    MVMCArray_ ARRAY;
};

/* CStruct */

typedef struct {
    void *cobj;
    MVMBlob *blob;
} MVMCStructBody_;

union MVMCStructBody {
    MVMPtrBody      VMPTR;
    MVMCStructBody_ STRUCT;
};

typedef struct {
    MVMObject common;
    MVMCStructBody body;
} MVMCStruct_;

union MVMCStruct {
    MVMPtr      VMPTR;
    MVMCStruct_ STRUCT;
};

/* CUnion */

typedef struct {
    void *cobj;
    MVMBlob *blob;
} MVMCUnionBody_;

union MVMCUnionBody {
    MVMPtrBody      VMPTR;
    MVMCUnionBody_  UNION;
};

typedef struct {
    MVMObject common;
    MVMCUnionBody body;
} MVMCUnion_;

union MVMCUnion {
    MVMPtr      VMPTR;
    MVMCUnion_  UNION;
};

/* CFlexStruct */

typedef struct {
    void *cobj;
    MVMBlob *blob;
    MVMCArray *flexibles;
} MVMCFlexStructBody_;

union MVMCFlexStructBody {
    MVMPtrBody          VMPTR;
    MVMCStructBody_     STRUCT;
    MVMCFlexStructBody_ FLEX_STRUCT;
};

typedef struct {
    MVMObject common;
    MVMCFlexStructBody body;
} MVMCFlexStruct_;

union MVMCFlexStruct {
    MVMPtr          VMPTR;
    MVMCStruct_     STRUCT;
    MVMCFlexStruct_ FLEX_STRUCT;
};

/* Initialization */
MVMREPROps * MVMBlob_initialize(MVMThreadContext *tc);
MVMREPROps * MVMPtr_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCScalar_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCPointer_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCArray_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCStruct_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCUnion_initialize(MVMThreadContext *tc);
MVMREPROps * MVMCFlexStruct_initialize(MVMThreadContext *tc);

/* Helper functions */
const MVMCScalarSpec * MVM_native_get_cscalar_spec(MVMThreadContext *tc,
        MVMint64 id);
