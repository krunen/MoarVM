#include "moarvm.h"

#define ALIGNOF(type) \
    ((MVMuint16)offsetof(struct { char dummy; type member; }, member))

#define DEF_FETCH(NAME, CTYPE, VMTYPE) static MVMObject * fetch_ ## NAME( \
        MVMThreadContext *tc, void *ptr) { \
    CTYPE value = *(CTYPE *)ptr; \
    MVMREPROps *repr = MVM_repr_get_by_id(tc, MVM_REPR_ID_P6 ## VMTYPE); \
    MVMObject  *type = repr->type_object_for(tc, NULL); \
    MVMObject  *box  = MVM_repr_alloc_init(tc, type); \
    MVM_repr_set_ ## VMTYPE(tc, box, (MVM ## VMTYPE ## 64)value); \
    return box; \
}

#define DEF_STORE(NAME, CTYPE, VMTYPE) static void store_ ## NAME( \
        MVMThreadContext *tc, void *ptr, MVMObject *obj) { \
    *(CTYPE *)ptr = (CTYPE)MVM_repr_get_ ## VMTYPE(tc, obj); \
}

#define INIT_SPEC(NAME, BIGNAME, CTYPE, BIGVMTYPE) { \
    sizeof (CTYPE), \
    ALIGNOF(CTYPE), \
    MVM_STORAGE_SPEC_CAN_BOX_ ## BIGVMTYPE, \
    MVM_CSCALAR_ ## BIGNAME, \
    #CTYPE, \
    fetch_ ## NAME, \
    store_ ## NAME \
}

typedef void func(void);

static MVMObject * fetch_void(MVMThreadContext *tc, void *ptr) {
    MVM_exception_throw_adhoc(tc, "cannot fetch from CScalar of type void");
}

DEF_FETCH(char, signed char, int)
DEF_FETCH(uchar, unsigned char, int)
DEF_FETCH(short, short, int)
DEF_FETCH(ushort, unsigned short, int)
DEF_FETCH(int, int, int)
DEF_FETCH(uint, unsigned int, int)
DEF_FETCH(long, long, int)
DEF_FETCH(ulong, unsigned long, int)
DEF_FETCH(llong, long long, int)
DEF_FETCH(ullong, unsigned long long, int)
DEF_FETCH(int8, int8_t, int)
DEF_FETCH(uint8, uint8_t, int)
DEF_FETCH(int16, int16_t, int)
DEF_FETCH(uint16, uint16_t, int)
DEF_FETCH(int32, int32_t, int)
DEF_FETCH(uint32, uint32_t, int)
DEF_FETCH(int64, int64_t, int)
DEF_FETCH(uint64, uint64_t, int)
DEF_FETCH(intptr, intptr_t, int)
DEF_FETCH(uintptr, uintptr_t, int)
DEF_FETCH(intmax, intmax_t, int)
DEF_FETCH(uintmax, uintmax_t, int)
DEF_FETCH(float, float, num)
DEF_FETCH(double, double, num)
DEF_FETCH(ldouble, long double, num)

static MVMObject * fetch_ptr(MVMThreadContext *tc, void *ptr) {
    void *value = *(void **)ptr;
    MVMObject *box = MVM_repr_alloc_init(tc, tc->instance->VMPtr_WHAT);

    ((MVMPtr *)box)->body.cobj = value;
    return box;
}

static MVMObject * fetch_fptr(MVMThreadContext *tc, void *ptr) {
    MVM_exception_throw_adhoc(tc, "TODO");
}

static void store_void(MVMThreadContext *tc, void *ptr, MVMObject *obj) {
    MVM_exception_throw_adhoc(tc, "cannot store into CScalar of type void");
}

DEF_STORE(char, signed char, int)
DEF_STORE(uchar, unsigned char, int)
DEF_STORE(short, short, int)
DEF_STORE(ushort, unsigned short, int)
DEF_STORE(int, int, int)
DEF_STORE(uint, unsigned int, int)
DEF_STORE(long, long, int)
DEF_STORE(ulong, unsigned long, int)
DEF_STORE(llong, long long, int)
DEF_STORE(ullong, unsigned long long, int)
DEF_STORE(int8, int8_t, int)
DEF_STORE(uint8, uint8_t, int)
DEF_STORE(int16, int16_t, int)
DEF_STORE(uint16, uint16_t, int)
DEF_STORE(int32, int32_t, int)
DEF_STORE(uint32, uint32_t, int)
DEF_STORE(int64, int64_t, int)
DEF_STORE(uint64, uint64_t, int)
DEF_STORE(intptr, intptr_t, int)
DEF_STORE(uintptr, uintptr_t, int)
DEF_STORE(intmax, intmax_t, int)
DEF_STORE(uintmax, uintmax_t, int)
DEF_STORE(float, float, num)
DEF_STORE(double, double, num)
DEF_STORE(ldouble, long double, num)

static void store_ptr(MVMThreadContext *tc, void *ptr, MVMObject *obj) {
    *(void **)ptr = ((MVMPtr *)obj)->body.cobj;
}

static void store_fptr(MVMThreadContext *tc, void *ptr, MVMObject *obj) {
    MVM_exception_throw_adhoc(tc, "TODO");
}

static const MVMCScalarSpec SPECS[MVM_CSCALAR_TYPE_COUNT] = {
    { 0, 0, 0, MVM_CSCALAR_VOID, "void", fetch_void, store_void },
    INIT_SPEC(char, CHAR, signed char, INT),
    INIT_SPEC(uchar, UCHAR, unsigned char, INT),
    INIT_SPEC(short, SHORT, short, INT),
    INIT_SPEC(ushort, USHORT, unsigned short, INT),
    INIT_SPEC(int, INT, int, INT),
    INIT_SPEC(uint, UINT, unsigned int, INT),
    INIT_SPEC(long, LONG, long, INT),
    INIT_SPEC(ulong, ULONG, unsigned long, INT),
    INIT_SPEC(llong, LLONG, long long, INT),
    INIT_SPEC(ullong, ULLONG, unsigned long long, INT),
    INIT_SPEC(int8, INT8, int8_t, INT),
    INIT_SPEC(uint8, UINT8, uint8_t, INT),
    INIT_SPEC(int16, INT16, int16_t, INT),
    INIT_SPEC(uint16, UINT16, uint16_t, INT),
    INIT_SPEC(int32, INT32, int32_t, INT),
    INIT_SPEC(uint32, UINT32, uint32_t, INT),
    INIT_SPEC(int64, INT64, int64_t, INT),
    INIT_SPEC(uint64, UINT64, uint64_t, INT),
    INIT_SPEC(intptr, INTPTR, intptr_t, INT),
    INIT_SPEC(uintptr, UINTPTR, uintptr_t, INT),
    INIT_SPEC(intmax, INTMAX, intmax_t, INT),
    INIT_SPEC(uintmax, UINTMAX, uintmax_t, INT),
    INIT_SPEC(float, FLOAT, float, NUM),
    INIT_SPEC(double, DOUBLE, double, NUM),
    INIT_SPEC(ldouble, LDOUBLE, long double, NUM),
    { sizeof (void *), ALIGNOF(void *), 0, MVM_CSCALAR_PTR, "void *",
            fetch_ptr, store_ptr },
    { sizeof (func *), ALIGNOF(func *), 0, MVM_CSCALAR_FPTR, "void (*)(void)",
            fetch_fptr, store_fptr },
};

static MVMREPROps this_repr;
static MVMContainerSpec container_spec;

const MVMCScalarSpec * MVM_native_get_cscalar_spec(MVMThreadContext *tc,
        MVMint64 id) {
    if (id < 0 || id >= MVM_CSCALAR_TYPE_COUNT)
        MVM_exception_throw_adhoc(tc, "illegal CScalar id %" PRIi64, id);

    return SPECS + id;
}

/* REPROps */

static MVMObject * type_object_for(MVMThreadContext *tc, MVMObject *HOW) {
    MVMSTable *st = MVM_gc_allocate_stable(tc, &this_repr, HOW);

    MVMROOT(tc, st, {
        MVMObject *obj = MVM_gc_allocate_type_object(tc, st);
        MVM_ASSIGN_REF(tc, st, st->WHAT, obj);
        st->size = sizeof(MVMCScalar);
        st->container_spec = &container_spec;
    });

    return st->WHAT;
}

static MVMObject * allocate(MVMThreadContext *tc, MVMSTable *st) {
    return MVM_gc_allocate_object(tc, st);
}

static void initialize(MVMThreadContext *tc, MVMSTable *st, MVMObject *root,
        void *data) {
    MVMCScalarBody_ *body = data;

    body->cobj = NULL;
    body->blob = NULL;
}

static void copy_to(MVMThreadContext *tc, MVMSTable *st, void *src,
        MVMObject *dest_root, void *dest) {
    MVMCScalarBody_ *src_body  = src;
    MVMCScalarBody_ *dest_body = dest;

    dest_body->cobj = src_body->cobj;
    MVM_ASSIGN_REF(tc, dest_root, dest_body->blob, src_body->blob);
}

static MVMStorageSpec get_storage_spec(MVMThreadContext *tc, MVMSTable *st) {
    const MVMCScalarSpec *scalar_spec = st->REPR_data;
    MVMStorageSpec spec;

    if (!scalar_spec)
        MVM_exception_throw_adhoc(tc,
                "cannot get storage spec from uncomposed CScalar type");

    spec.inlineable      = MVM_STORAGE_SPEC_REFERENCE;
    spec.boxed_primitive = MVM_STORAGE_SPEC_BP_NONE;
    spec.can_box         = scalar_spec->can_box;

    return spec;
}

static void gc_mark(MVMThreadContext *tc, MVMSTable *st, void *data,
        MVMGCWorklist *worklist) {
    MVMCScalarBody_ *body = data;

    if (body->blob)
        MVM_gc_worklist_add(tc, worklist, &body->blob);
}

static void compose(MVMThreadContext *tc, MVMSTable *st, MVMObject *info) {
    MVMStorageSpec spec = REPR(info)->get_storage_spec(tc, STABLE(info));

    if (!spec.can_box & MVM_STORAGE_SPEC_CAN_BOX_INT)
        MVM_exception_throw_adhoc(tc, "can only use arguments "
                "that can unbox to int in CScalar composition");

    st->REPR_data = (void *)MVM_native_get_cscalar_spec(tc,
            MVM_repr_get_int(tc, info));
}

static MVMREPROps this_repr = {
    type_object_for,
    allocate,
    initialize,
    copy_to,
    NULL, /* attr_funcs */
    NULL, /* box_funcs, */
    NULL, /* pos_funcs */
    NULL, /* ass_funcs */
    NULL, /* elems */
    get_storage_spec,
    NULL, /* change_type */
    NULL, /* serialize */
    NULL, /* deserialize */
    NULL, /* serialize_repr_data */
    NULL, /* deserialize_repr_data */
    NULL, /* deserialize_stable_size */
    gc_mark,
    NULL, /* gc_free */
    NULL, /* gc_cleanup */
    NULL, /* gc_mark_repr_data */
    NULL, /* gc_free_repr_data */
    compose,
    NULL, /* name */
    0, /* ID */
    0, /* refs_frames */
};

/* ContainerSpec */

static const MVMCScalarSpec * get_spec_checked(MVMThreadContext *tc,
        MVMObject *scalar) {
    const MVMCScalarSpec *spec = STABLE(scalar)->REPR_data;

    if (!spec)
        MVM_exception_throw_adhoc(tc,
                "cannot get scalar spec from uncomposed CScalar");

    return spec;
}

static void fetch(MVMThreadContext *tc, MVMObject *cont, MVMRegister *res) {
    const MVMCScalarSpec *spec = get_spec_checked(tc, cont);
    void *ptr = ((MVMPtr *)cont)->body.cobj;

    if (!ptr)
        MVM_exception_throw_adhoc(tc, "cannot fetch from null CScalar");

    if (spec->id == MVM_CSCALAR_PTR)
        MVMROOT(tc, cont, {
            res->o = spec->fetch(tc, ptr);
            ((MVMPtr *)res->o)->body.blob = ((MVMPtr *)cont)->body.blob;
        });
    else res->o = spec->fetch(tc, ptr);
}

static void store_unchecked(MVMThreadContext *tc, MVMObject *cont,
        MVMObject *obj) {
    const MVMCScalarSpec *spec = STABLE(cont)->REPR_data;
    void *ptr = ((MVMPtr *)cont)->body.cobj;

    spec->store(tc, ptr, obj);
}

static void store(MVMThreadContext *tc, MVMObject *cont, MVMObject *obj) {
    const MVMCScalarSpec *scalar_spec = get_spec_checked(tc, cont);
    MVMStorageSpec obj_spec = REPR(obj)->get_storage_spec(tc, STABLE(obj));
    void *ptr = ((MVMPtr *)cont)->body.cobj;

    if (scalar_spec->can_box & obj_spec.can_box); /* OK */
    else if (scalar_spec->id == MVM_CSCALAR_PTR) {
        switch (REPR(obj)->ID) {
            case MVM_REPR_ID_VMPtr:
            case MVM_REPR_ID_CScalar:
            case MVM_REPR_ID_CPointer:
            case MVM_REPR_ID_CArray:
            case MVM_REPR_ID_CStruct:
            case MVM_REPR_ID_CUnion:
            case MVM_REPR_ID_CFlexStruct:
                break;

            default:
                MVM_exception_throw_adhoc(tc,
                        "cannot store non-pointer in CScalar of type void *");
        }
    }
    else MVM_exception_throw_adhoc(tc, "cannot store type %" PRIu16
            " in CScalar of type %s", obj_spec.can_box, scalar_spec->cname);

    if (!ptr)
        MVM_exception_throw_adhoc(tc, "cannot store into null CScalar");

    scalar_spec->store(tc, ptr, obj);
}

static void gc_mark_data(MVMThreadContext *tc, MVMSTable *st,
        MVMGCWorklist *worklist) {
    /* nothing to mark */
}

static MVMContainerSpec container_spec = {
    fetch,
    store,
    store_unchecked,
    NULL, /* name */
    gc_mark_data,
    NULL, /* gc_free_data */
    NULL, /* serialize */
    NULL, /* deserialize */
};

MVMREPROps * MVMCScalar_initialize(MVMThreadContext *tc) {
    MVMuint16 id;

    for (id = 0; id < MVM_CSCALAR_TYPE_COUNT; id++) {
        MVMSTable *st = MVM_gc_allocate_stable(tc, &this_repr, NULL);

        MVMROOT(tc, st, {
            MVMObject *WHAT = MVM_gc_allocate_type_object(tc, st);
            tc->instance->CScalar_WHATs[id] = WHAT;
            MVM_ASSIGN_REF(tc, st, st->WHAT, WHAT);
            st->size = sizeof(MVMPtr);
            st->container_spec = &container_spec;
            st->REPR_data = (void *)(SPECS + id);
        });

        MVM_gc_root_add_permanent(tc,
                (MVMCollectable **)&tc->instance->CScalar_WHATs[id]);
    }

    return &this_repr;
}
