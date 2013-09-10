#include "moarvm.h"
#include "native/ops.h"

MVMObject * MVM_native_ptrcast(MVMThreadContext *tc, MVMObject *type_obj,
        MVMObject *ptr_obj) {
    MVMuint32 ptr_id  = REPR(ptr_obj)->ID;
    MVMuint32 type_id = REPR(type_obj)->ID;
    void *ptr;

    switch (ptr_id) {
        case MVM_REPR_ID_CPointer:
        case MVM_REPR_ID_CScalar:
        case MVM_REPR_ID_CArray:
        case MVM_REPR_ID_CStruct:
        case MVM_REPR_ID_CUnion:
        case MVM_REPR_ID_CFlexibleStruct:
            ptr = ((MVMCPointer *)ptr_obj)->body.cobj;
            break;
        default:
            MVM_exception_throw_adhoc(tc,
                    "cannot cast from non-pointer repr %" PRIu32, ptr_id);
    }

    switch (type_id) {
        case MVM_REPR_ID_CPointer:
        case MVM_REPR_ID_CScalar:
        case MVM_REPR_ID_CArray:
        case MVM_REPR_ID_CStruct:
        case MVM_REPR_ID_CUnion:
        case MVM_REPR_ID_CFlexibleStruct:
            MVM_exception_throw_adhoc(tc, "ptrcast NYI");
            // TODO: if there's a blob, check bounds
            break;

        default:
            MVM_exception_throw_adhoc(tc, "cannot cast to non-pointer repr %"
                    PRIu32, type_id);
    }
}

void MVM_native_ptrsetblob(MVMThreadContext *tc, MVMObject *ptr_obj,
        MVMObject *blob_obj, MVMuint64 offset) {
    MVMuint32 ptr_id  = REPR(ptr_obj)->ID;
    MVMuint32 blob_id = REPR(blob_obj)->ID;
    MVMCPointer *ptr;
    MVMCBlob *blob;

    if (ptr_id != MVM_REPR_ID_CPointer)
        MVM_exception_throw_adhoc(tc,
                "cannot set blob on non-pointer repr %" PRIu32, ptr_id);

    if (blob_id != MVM_REPR_ID_CBlob)
        MVM_exception_throw_adhoc(tc, "cannot set non-blob repr %" PRIu32
                " on pointer", blob_id);

    ptr  = (MVMCPointer *)ptr;
    blob = (MVMCBlob *)blob;

    if (offset > blob->body.size)
        MVM_exception_throw_adhoc(tc, "pointer offset %" PRIu64
            " out of blob bounds 0..%" PRIu64, offset, blob->body.size);

    ptr->body.cobj = blob->body.storage + offset;
    MVM_ASSIGN_REF(tc, ptr, ptr->body.blob, blob);
}

MVMObject * MVM_native_bloballoc(MVMThreadContext *tc, MVMuint64 size) {
    return NULL;
}
