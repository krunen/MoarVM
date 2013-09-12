#include "moarvm.h"
#include "native/ops.h"

MVMObject * MVM_native_bloballoc(MVMThreadContext *tc, MVMuint64 size) {
    MVMObject     *WHAT = tc->instance->VMBlob_WHAT;
    MVMObject     *blob = MVM_gc_allocate_object(tc, STABLE(WHAT));
    MVMBlobBody *body = &((MVMBlob *)blob)->body;

    body->storage = malloc(size);
    body->size    = size;
    body->refmap  = NULL;

    return blob;
}

MVMObject * MVM_native_blobptr(MVMThreadContext *tc, MVMObject *blob,
        MVMObject *type) {
    MVMuint32  blob_id = REPR(blob)->ID;
    MVMuint32  type_id = REPR(type)->ID;
    MVMuint64  blob_size;
    MVMuint64 *type_rdata, type_size;
    MVMPtr *ptr;

    if (blob_id != MVM_REPR_ID_VMBlob)
        MVM_exception_throw_adhoc(tc, "expected blob repr %" PRIu32
                " but got %" PRIu32, blob_id, type_id);

    blob_size = ((MVMBlob *)blob)->body.size;

    switch (type_id) {
        case MVM_REPR_ID_VMPtr:
        case MVM_REPR_ID_CScalar:
        case MVM_REPR_ID_CPointer:
        case MVM_REPR_ID_CArray:
        case MVM_REPR_ID_CStruct:
        case MVM_REPR_ID_CUnion:
        case MVM_REPR_ID_CFlexStruct:
            type_rdata = STABLE(type)->REPR_data;
            type_size  = type_rdata ? *type_rdata : 0;
            break;

        default:
            MVM_exception_throw_adhoc(tc, "cannot convert blob address "
                    "to non-pointer repr %" PRIu32, type_id);
    }

    if (type_size > blob_size)
        MVM_exception_throw_adhoc(tc, "blob of size %" PRIu64
                " is too small for pointer repr %" PRIu32
                " of size %" PRIu64, blob_size, type_id, type_size);

    MVMROOT(tc, blob, {
        ptr = (MVMPtr *)MVM_repr_alloc_init(tc, type);
        ptr->body.cobj = ((MVMBlob *)blob)->body.storage;
        ptr->body.blob = (MVMBlob *)blob;
    });

    return (MVMObject *)ptr;
}

MVMObject * MVM_native_ptrcast(MVMThreadContext *tc, MVMObject *src,
        MVMObject *type, MVMint64 offset) {
    MVMuint32  src_id    = REPR(src)->ID;
    MVMuint32  dest_id   = REPR(type)->ID;
    MVMuint64 *dest_rdata, dest_size;
    MVMPtr *dest;
    MVMPtrBody *body;
    MVMBlob *blob;
    void *cptr;

    switch (src_id) {
        case MVM_REPR_ID_VMPtr:
        case MVM_REPR_ID_CScalar:
        case MVM_REPR_ID_CPointer:
        case MVM_REPR_ID_CArray:
        case MVM_REPR_ID_CStruct:
        case MVM_REPR_ID_CUnion:
        case MVM_REPR_ID_CFlexStruct:
            body = &((MVMPtr *)src)->body;
            cptr = (char *)body->cobj + offset;
            blob = body->blob;
            break;

        default:
            MVM_exception_throw_adhoc(tc,
                    "cannot cast from non-pointer repr %" PRIu32, src_id);
    }

    switch (dest_id) {
        case MVM_REPR_ID_VMPtr:
        case MVM_REPR_ID_CScalar:
        case MVM_REPR_ID_CPointer:
        case MVM_REPR_ID_CArray:
        case MVM_REPR_ID_CStruct:
        case MVM_REPR_ID_CUnion:
        case MVM_REPR_ID_CFlexStruct:
            dest_rdata = STABLE(type)->REPR_data;
            dest_size = dest_rdata ? *dest_rdata : 0;
            break;

        default:
            MVM_exception_throw_adhoc(tc, "cannot cast to non-pointer repr %"
                    PRIu32, dest_id);
    }

    if (body->blob)
    {
        uintptr_t lower = (uintptr_t)body->blob->body.storage;
        uintptr_t upper = lower + body->blob->body.size;
        uintptr_t value = (uintptr_t)cptr;

        if (value < lower || value + dest_size > upper)
            MVM_exception_throw_adhoc(tc, "pointer cast target range %" PRIxPTR
                    "..%" PRIxPTR " overflows blob range %" PRIxPTR "..%"
                    PRIxPTR, value, value + dest_size, lower, upper);
    }

    MVMROOT(tc, blob, {
        dest = (MVMPtr *)MVM_repr_alloc_init(tc, type);
        dest->body.cobj = cptr;
        dest->body.blob = (MVMBlob *)blob;
    });

    return (MVMObject *)dest;
}

MVMuint64 MVM_native_sizeof(MVMThreadContext *tc, MVMObject *ptr) {
    MVMuint16 id = REPR(ptr)->ID;
    MVMuint64 *size = STABLE(ptr)->REPR_data;

    switch (id) {
        case MVM_REPR_ID_CScalar:
        case MVM_REPR_ID_CPointer:
        case MVM_REPR_ID_CArray:
        case MVM_REPR_ID_CStruct:
        case MVM_REPR_ID_CUnion:
        case MVM_REPR_ID_CFlexStruct:
            break;

        default:
            MVM_exception_throw_adhoc(tc, "can determine size of C types");
    }

    if (!size)
        MVM_exception_throw_adhoc(tc,
                "can only determine size of composed types");

    return *size;
}
