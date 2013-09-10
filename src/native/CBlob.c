#include "moarvm.h"

/* stub type for now */

static MVMStorageSpec get_storage_spec(MVMThreadContext *tc, MVMSTable *st) {
    MVMStorageSpec spec;
    spec.inlineable      = MVM_STORAGE_SPEC_REFERENCE;
    spec.boxed_primitive = MVM_STORAGE_SPEC_BP_NONE;
    spec.can_box         = 0;
    return spec;
}

static void gc_mark(MVMThreadContext *tc, MVMSTable *st, void *data,
        MVMGCWorklist *worklist) {
    MVMCPointerBody *body = data;

    if (body->blob)
        MVM_gc_worklist_add(tc, worklist, body->blob);
}

static void gc_free(MVMThreadContext *tc, MVMObject *obj) {
    MVMCBlobBody *body = &((MVMCBlob *)obj)->body;

    MVM_checked_free_null(body->storage);
    MVM_checked_free_null(body->refmap);
    body->size = 0;
}

static MVMREPROps this_repr = {
    NULL, /* type_object_for, */
    NULL, /* allocate, */
    NULL, /* initialize */
    NULL, /* copy_to, */
    NULL, /* attr_funcs, */
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
    gc_free,
    NULL, /* gc_cleanup */
    NULL, /* gc_mark_repr_data */
    NULL, /* gc_free_repr_data */
    NULL, /* compose, */
    NULL, /* name */
    0, /* ID */
    0, /* refs_frames */
};

MVMREPROps * MVMCBlob_initialize(MVMThreadContext *tc) {
    MVMSTable *st;
    MVMObject *blob;

    st = MVM_gc_allocate_stable(tc, &this_repr, NULL);
    MVMROOT(tc, st, {
        MVMObject *WHAT = MVM_gc_allocate_type_object(tc, st);
        tc->instance->CBlob_WHAT = WHAT;
        MVM_ASSIGN_REF(tc, st, st->WHAT, WHAT);
        st->size = sizeof(MVMCBlob);
    });

    MVM_gc_root_add_permanent(tc, (MVMCollectable **)&tc->instance->CBlob_WHAT);

    return &this_repr;
}
