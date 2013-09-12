#include "moarvm.h"

#define ALIGNOF(type) \
    ((MVMuint16)offsetof(struct { char dummy; type member; }, member))

typedef void func(void);

static const MVMCScalarSpec SPECS[MVM_CSCALAR_TYPE_COUNT] = {
    { 0, 0, 0, MVM_CSCALAR_VOID, "void" },
    { 1, 1, MVM_STORAGE_SPEC_CAN_BOX_INT, MVM_CSCALAR_CHAR, "signed char" },
    { 1, 1, MVM_STORAGE_SPEC_CAN_BOX_INT, MVM_CSCALAR_UCHAR, "unsigned char" },
    { sizeof (short), ALIGNOF(short), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_SHORT, "short" },
    { sizeof (short), ALIGNOF(short), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_USHORT, "unsigned short" },
    { sizeof (int), ALIGNOF(int), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_INT, "int" },
    { sizeof (int), ALIGNOF(int), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_UINT, "unsigned int" },
    { sizeof (long), ALIGNOF(long), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_LONG, "long" },
    { sizeof (long), ALIGNOF(long), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_ULONG, "unsigned long" },
    { sizeof (long long), ALIGNOF(long long), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_LLONG, "long long" },
    { sizeof (long long), ALIGNOF(long long), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_ULLONG, "unsigned long long" },
    { sizeof (int8_t), ALIGNOF(int8_t), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_INT8, "int8_t" },
    { sizeof (int8_t), ALIGNOF(int8_t), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_UINT8, "uint8_t" },
    { sizeof (int16_t), ALIGNOF(int16_t), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_INT16, "int16_t" },
    { sizeof (int16_t), ALIGNOF(int16_t), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_UINT16, "uint16_t" },
    { sizeof (int32_t), ALIGNOF(int32_t), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_INT32, "int32_t" },
    { sizeof (int32_t), ALIGNOF(int32_t), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_UINT32, "uint32_t" },
    { sizeof (int64_t), ALIGNOF(int64_t), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_INT64, "int64_t" },
    { sizeof (int64_t), ALIGNOF(int64_t), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_UINT64, "uint64_t" },
    { sizeof (intptr_t), ALIGNOF(intptr_t), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_INTPTR, "intptr_t" },
    { sizeof (intptr_t), ALIGNOF(intptr_t), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_UINTPTR, "uintptr_t" },
    { sizeof (intmax_t), ALIGNOF(intmax_t), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_INTMAX, "intmax_t" },
    { sizeof (intmax_t), ALIGNOF(intmax_t), MVM_STORAGE_SPEC_CAN_BOX_INT,
            MVM_CSCALAR_UINTMAX, "uintmax_t" },
    { sizeof (float), ALIGNOF(float), MVM_STORAGE_SPEC_CAN_BOX_NUM,
            MVM_CSCALAR_FLOAT, "float" },
    { sizeof (double), ALIGNOF(double), MVM_STORAGE_SPEC_CAN_BOX_NUM,
            MVM_CSCALAR_DOUBLE, "double" },
    { sizeof (long double), ALIGNOF(long double), MVM_STORAGE_SPEC_CAN_BOX_NUM,
            MVM_CSCALAR_LDOUBLE, "long double" },
    { sizeof (void *), ALIGNOF(void *), 0, MVM_CSCALAR_PTR, "void *" },
    { sizeof (func *), ALIGNOF(func *), 0, MVM_CSCALAR_FPTR, "void (*)(void)" },
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
    MVMuint16 id = spec->id;
    union { intmax_t i; uintmax_t u; long double n; } value;
    MVMREPROps *repr;
    MVMObject *type, *box;

    if (!ptr)
        MVM_exception_throw_adhoc(tc, "cannot fetch from null CScalar");

    switch (id) {
        case MVM_CSCALAR_VOID:
            MVM_exception_throw_adhoc(tc,
                    "cannot fetch from CScalar of type void");
            break;

        case MVM_CSCALAR_CHAR:
            value.i = *(signed char *)ptr;
            goto box_i;

        case MVM_CSCALAR_UCHAR:
            value.u = *(unsigned char *)ptr;
            goto box_u;

        case MVM_CSCALAR_SHORT:
            value.i = *(short *)ptr;
            goto box_i;

        case MVM_CSCALAR_USHORT:
            value.u = *(unsigned short *)ptr;
            goto box_u;

        case MVM_CSCALAR_INT:
            value.i = *(int *)ptr;
            goto box_i;

        case MVM_CSCALAR_UINT:
            value.u = *(unsigned int *)ptr;
            goto box_u;

        case MVM_CSCALAR_LONG:
            value.i = *(long *)ptr;
            goto box_i;

        case MVM_CSCALAR_ULONG:
            value.u = *(unsigned long *)ptr;
            goto box_u;

        case MVM_CSCALAR_LLONG:
            value.i = *(long long *)ptr;
            goto box_i;

        case MVM_CSCALAR_ULLONG:
            value.u = *(unsigned long long *)ptr;
            goto box_u;

        case MVM_CSCALAR_INT8:
            value.i = *(int8_t *)ptr;
            goto box_i;

        case MVM_CSCALAR_UINT8:
            value.u = *(uint8_t *)ptr;
            goto box_u;

        case MVM_CSCALAR_INT16: {
            value.i = *(int16_t *)ptr;
            goto box_i;
        }

        case MVM_CSCALAR_UINT16:
            value.u = *(uint16_t *)ptr;
            goto box_u;

        case MVM_CSCALAR_INT32:
            value.i = *(int32_t *)ptr;
            goto box_i;

        case MVM_CSCALAR_UINT32:
            value.u = *(uint32_t *)ptr;
            goto box_u;

        case MVM_CSCALAR_INT64:
            value.i = *(int64_t *)ptr;
            goto box_i;

        case MVM_CSCALAR_UINT64:
            value.u = *(uint64_t *)ptr;
            goto box_u;

        case MVM_CSCALAR_INTPTR:
            value.i = *(intptr_t *)ptr;
            goto box_i;

        case MVM_CSCALAR_UINTPTR:
            value.u = *(uintptr_t *)ptr;
            goto box_u;

        case MVM_CSCALAR_INTMAX:
            value.i = *(intmax_t *)ptr;
            goto box_i;

        case MVM_CSCALAR_UINTMAX:
            value.u = *(uintmax_t *)ptr;
            goto box_u;

        case MVM_CSCALAR_FLOAT:
            value.n = *(float *)ptr;
            goto box_n;

        case MVM_CSCALAR_DOUBLE:
            value.n = *(double *)ptr;
            goto box_n;

        case MVM_CSCALAR_LDOUBLE:
            value.n = *(long double *)ptr;
            goto box_n;

        case MVM_CSCALAR_PTR:
        case MVM_CSCALAR_FPTR:
            MVM_exception_throw_adhoc(tc, "TODO");

        default:
            MVM_exception_throw_adhoc(tc, "invalid CScalar id %" PRIu16, id);
    }

box_i:
box_u:
    repr = MVM_repr_get_by_id(tc, MVM_REPR_ID_P6int);
    type = repr->type_object_for(tc, NULL);
    box  = MVM_repr_alloc_init(tc, type);
    MVM_repr_set_int(tc, box, value.i);
    res->o = box;
    return;

box_n:
    repr = MVM_repr_get_by_id(tc, MVM_REPR_ID_P6num);
    type = repr->type_object_for(tc, NULL);
    box  = MVM_repr_alloc_init(tc, type);
    MVM_repr_set_num(tc, box, value.n);
    res->o = box;
    return;
}

static void do_store(MVMThreadContext *tc, MVMuint16 id, void *ptr,
        MVMObject *obj) {
    switch (id) {
        case MVM_CSCALAR_VOID:
            MVM_exception_throw_adhoc(tc,
                    "cannot store into CScalar of type void");
            break;

        case MVM_CSCALAR_CHAR:
            *(signed char *)ptr = (signed char)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_UCHAR:
            *(unsigned char *)ptr = (unsigned char)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_SHORT:
            *(short *)ptr = (short)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_USHORT:
            *(unsigned short *)ptr = (unsigned short)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_INT:
            *(int *)ptr = (int)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_UINT:
            *(unsigned int *)ptr = (unsigned int)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_LONG:
            *(long *)ptr = (long)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_ULONG:
            *(unsigned long *)ptr = (unsigned long)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_LLONG:
            *(long long *)ptr = (long long)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_ULLONG:
            *(unsigned long long *)ptr = (unsigned long long)MVM_repr_get_int(
                    tc, obj);
            break;

        case MVM_CSCALAR_INT8:
            *(int8_t *)ptr = (int8_t)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_UINT8:
            *(uint8_t *)ptr = (uint8_t)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_INT16:
            *(int16_t *)ptr = (int16_t)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_UINT16:
            *(uint16_t *)ptr = (uint16_t)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_INT32:
            *(int32_t *)ptr = (int32_t)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_UINT32:
            *(uint32_t *)ptr = (uint32_t)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_INT64:
            *(int64_t *)ptr = (int64_t)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_UINT64:
            *(uint64_t *)ptr = (uint64_t)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_INTPTR:
            *(intptr_t *)ptr = (intptr_t)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_UINTPTR:
            *(uintptr_t *)ptr = (uintptr_t)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_INTMAX:
            *(intmax_t *)ptr = (intmax_t)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_UINTMAX:
            *(uintmax_t *)ptr = (uintmax_t)MVM_repr_get_int(tc, obj);
            break;

        case MVM_CSCALAR_FLOAT:
            *(float *)ptr = (float)MVM_repr_get_num(tc, obj);
            break;

        case MVM_CSCALAR_DOUBLE:
            *(double *)ptr = (double)MVM_repr_get_num(tc, obj);
            break;

        case MVM_CSCALAR_LDOUBLE:
            *(long double *)ptr = (long double)MVM_repr_get_num(tc, obj);
            break;

        case MVM_CSCALAR_PTR:
        case MVM_CSCALAR_FPTR:
            MVM_exception_throw_adhoc(tc, "TODO");

        default:
            MVM_exception_throw_adhoc(tc, "invalid CScalar id %" PRIu16, id);
    }
}

static void store_unchecked(MVMThreadContext *tc, MVMObject *cont,
        MVMObject *obj) {
    const MVMCScalarSpec *spec = STABLE(cont)->REPR_data;
    void *ptr = ((MVMPtr *)cont)->body.cobj;

    do_store(tc, spec->id, ptr, obj);
}

static void store(MVMThreadContext *tc, MVMObject *cont, MVMObject *obj) {
    const MVMCScalarSpec *scalar_spec = get_spec_checked(tc, cont);
    MVMStorageSpec obj_spec = REPR(obj)->get_storage_spec(tc, STABLE(obj));
    void *ptr = ((MVMPtr *)cont)->body.cobj;

    if (!(scalar_spec->can_box & obj_spec.can_box))
        MVM_exception_throw_adhoc(tc, "cannot store type %" PRIu16
                " in CScalar of type %s", obj_spec.can_box, scalar_spec->cname);

    if (!ptr)
        MVM_exception_throw_adhoc(tc, "cannot store into null CScalar");

    do_store(tc, scalar_spec->id, ptr, obj);
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
