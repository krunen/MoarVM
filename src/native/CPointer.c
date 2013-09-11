#include "moarvm.h"

static MVMREPROps this_repr;
static MVMREPROps_Boxing box_funcs;

static MVMObject * type_object_for(MVMThreadContext *tc, MVMObject *HOW) {
    MVMSTable *st = MVM_gc_allocate_stable(tc, &this_repr, HOW);

    MVMROOT(tc, st, {
        MVMObject *obj = MVM_gc_allocate_type_object(tc, st);
        MVM_ASSIGN_REF(tc, st, st->WHAT, obj);
        st->size = sizeof(MVMCPointer);
    });

    return st->WHAT;
}

static MVMObject * allocate(MVMThreadContext *tc, MVMSTable *st) {
    return MVM_gc_allocate_object(tc, st);
}

static void initialize(MVMThreadContext *tc, MVMSTable *st, MVMObject *root,
        void *data) {
    MVMCPointerBody *body = data;

    body->cobj = NULL;
    body->blob = NULL;
}

static void copy_to(MVMThreadContext *tc, MVMSTable *st, void *src,
        MVMObject *dest_root, void *dest) {
    MVMCPointerBody *src_ptr  = src;
    MVMCPointerBody *dest_ptr = dest;

    dest_ptr->cobj = src_ptr->cobj;
    MVM_ASSIGN_REF(tc, dest_root, dest_ptr->blob, src_ptr->blob);
}

static void set_int(MVMThreadContext *tc, MVMSTable *st, MVMObject *root,
        void *data, MVMint64 value) {
    ((MVMCPointerBody *)data)->cobj = (void *)value;
}

static MVMint64 get_int(MVMThreadContext *tc, MVMSTable *st, MVMObject *root,
        void *data) {
    return (MVMint64)((MVMCPointerBody *)data)->cobj;
}

static void set_num(MVMThreadContext *tc, MVMSTable *st, MVMObject *root,
        void *data, MVMnum64 value) {
    MVM_exception_throw_adhoc(tc,
            "CPointer representation cannot box a native num");
}

static MVMnum64 get_num(MVMThreadContext *tc, MVMSTable *st, MVMObject *root,
        void *data) {
    MVM_exception_throw_adhoc(tc,
            "CPointer representation cannot unbox to a native num");
}

static void set_str(MVMThreadContext *tc, MVMSTable *st, MVMObject *root,
        void *data, MVMString *value) {
    MVM_exception_throw_adhoc(tc,
            "CPointer representation cannot box a native string");
}

static MVMString * get_str(MVMThreadContext *tc, MVMSTable *st,
        MVMObject *root, void *data) {
    MVM_exception_throw_adhoc(tc,
            "CPointer representation cannot unbox to a native string");
}

static void * get_boxed_ref(MVMThreadContext *tc, MVMSTable *st,
        MVMObject *root, void *data, MVMuint32 repr_id) {
    MVM_exception_throw_adhoc(tc,
            "CPointer representation cannot unbox to other types");
}

static MVMStorageSpec get_storage_spec(MVMThreadContext *tc, MVMSTable *st) {
    MVMStorageSpec spec;
    spec.inlineable      = MVM_STORAGE_SPEC_REFERENCE;
    spec.boxed_primitive = MVM_STORAGE_SPEC_BP_NONE;
    spec.can_box         = MVM_STORAGE_SPEC_CAN_BOX_INT;
    return spec;
}

static void gc_mark(MVMThreadContext *tc, MVMSTable *st, void *data,
        MVMGCWorklist *worklist) {
    MVMCPointerBody *body = data;

    if (body->blob)
        MVM_gc_worklist_add(tc, worklist, body->blob);
}

static void compose(MVMThreadContext *tc, MVMSTable *st, MVMObject *info) {
    /* noop */
}

static MVMREPROps this_repr = {
    type_object_for,
    allocate,
    initialize,
    copy_to,
    NULL, /* attr_funcs */
    &box_funcs,
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

static MVMREPROps_Boxing box_funcs = {
    set_int,
    get_int,
    set_num,
    get_num,
    set_str,
    get_str,
    get_boxed_ref,
};

MVMREPROps * MVMCPointer_initialize(MVMThreadContext *tc) {
    MVMSTable *st = MVM_gc_allocate_stable(tc, &this_repr, NULL);

    MVMROOT(tc, st, {
        MVMObject *WHAT = MVM_gc_allocate_type_object(tc, st);
        tc->instance->CPointer_WHAT = WHAT;
        MVM_ASSIGN_REF(tc, st, st->WHAT, WHAT);
        st->size = sizeof(MVMCPointer);
    });

    MVM_gc_root_add_permanent(tc,
            (MVMCollectable **)&tc->instance->CPointer_WHAT);

    return &this_repr;
}
