#include "moarvm.h"
#include "native/ops.h"

MVMObject * MVM_native_bloballoc(MVMThreadContext *tc, MVMuint64 size) {
    MVMObject    *WHAT = tc->instance->CBlob_WHAT;
    MVMObject    *blob = MVM_gc_allocate_object(tc, STABLE(WHAT));
    MVMCBlobBody *body = &((MVMCBlob *)blob)->body;

    body->storage = malloc(size);
    body->size    = size;
    body->refmap  = NULL;

    return blob;
}

MVMObject * MVM_native_blobptr(MVMThreadContext *tc, MVMObject *blob,
        MVMObject *type) {
    MVMuint32    blob_id = REPR(blob)->ID;
    MVMuint32    type_id = REPR(type)->ID;
    MVMuint64    blob_size;
    MVMuint64   *type_data, type_size;
    MVMCPointer *ptr;

    if (blob_id != MVM_REPR_ID_CBlob)
        MVM_exception_throw_adhoc(tc, "expected blob repr %" PRIu32
                " but got %" PRIu32, blob_id, type_id);

    blob_size = ((MVMCBlob *)blob)->body.size;

    switch (type_id) {
        case MVM_REPR_ID_CPointer:
        case MVM_REPR_ID_CScalar:
        case MVM_REPR_ID_CArray:
        case MVM_REPR_ID_CStruct:
        case MVM_REPR_ID_CUnion:
        case MVM_REPR_ID_CFlexibleStruct:
            type_data = STABLE(type)->REPR_data;
            type_size = type_data ? *type_data : 0;
            break;

        default:
            MVM_exception_throw_adhoc(tc, "cannot convert blob address "
                    "to non-pointer repr %" PRIu32, type_id);
    }

    if (type_size > blob_size)
        MVM_exception_throw_adhoc(tc, "blob of size %" PRIu64
                "is too small for pointer repr %" PRIu32
                " of size %" PRIu64, blob_size, type_id, type_size);

    MVMROOT(tc, blob, {
        ptr = (MVMCPointer *)MVM_repr_alloc_init(tc, type);
        ptr->body.cobj = ((MVMCBlob *)blob)->body.storage;
        ptr->body.blob = (MVMCBlob *)blob;
    });

    return (MVMObject *)ptr;
}

MVMObject * MVM_native_ptrcast(MVMThreadContext *tc, MVMObject *base,
        MVMObject *type, MVMint64 offset) {
    MVMuint32  base_id   = REPR(base)->ID;
    MVMuint32  type_id   = REPR(base)->ID;
    MVMuint64 *type_data, type_size;
    MVMCPointerBody *body;
    void *ptr;

    switch (base_id) {
        case MVM_REPR_ID_CPointer:
        case MVM_REPR_ID_CScalar:
        case MVM_REPR_ID_CArray:
        case MVM_REPR_ID_CStruct:
        case MVM_REPR_ID_CUnion:
        case MVM_REPR_ID_CFlexibleStruct:
            body = &((MVMCPointer *)base)->body;
            ptr  = (char *)body->cobj + offset;
            break;

        default:
            MVM_exception_throw_adhoc(tc,
                    "cannot cast from non-pointer repr %" PRIu32, base_id);
    }

    switch (type_id) {
        case MVM_REPR_ID_CPointer:
        case MVM_REPR_ID_CScalar:
        case MVM_REPR_ID_CArray:
        case MVM_REPR_ID_CStruct:
        case MVM_REPR_ID_CUnion:
        case MVM_REPR_ID_CFlexibleStruct:
            type_data = STABLE(type)->REPR_data;
            type_size = type_data ? *type_data : 0;
            break;

        default:
            MVM_exception_throw_adhoc(tc, "cannot cast to non-pointer repr %"
                    PRIu32, type_id);
    }

    if (body->blob)
    {
        uintptr_t lower = (uintptr_t)body->blob->body.storage;
        uintptr_t upper = lower + body->blob->body.size;
        uintptr_t value = (uintptr_t)ptr;

        if (value < lower || value + type_size > upper)
            MVM_exception_throw_adhoc(tc, "pointer cast yields range %" PRIxPTR
                    "..%" PRIxPTR " overflowing blob range %" PRIxPTR "..%"
                    PRIxPTR, value, value + type_size, lower, upper);
    }

    switch (type_id) {
        case MVM_REPR_ID_CPointer:
        case MVM_REPR_ID_CScalar:
        case MVM_REPR_ID_CArray:
        case MVM_REPR_ID_CStruct:
        case MVM_REPR_ID_CUnion:
        case MVM_REPR_ID_CFlexibleStruct:
            MVM_exception_throw_adhoc(tc, "ptrcast NYI");
    }

    return NULL;
}
