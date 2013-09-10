MVMObject * MVM_native_ptrcast(MVMThreadContext *tc, MVMObject *type_obj,
        MVMObject *ptr_obj);

void MVM_native_ptrsetblob(MVMThreadContext *tc, MVMObject *ptr_obj,
        MVMObject *blob_obj, MVMuint64 offset);

MVMObject * MVM_native_bloballoc(MVMThreadContext *tc, MVMuint64 size);
