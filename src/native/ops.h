MVMObject * MVM_native_bloballoc(MVMThreadContext *tc, MVMuint64 size);

MVMObject * MVM_native_blobptr(MVMThreadContext *tc, MVMObject *blob,
        MVMObject *type);

MVMObject * MVM_native_ptrcast(MVMThreadContext *tc, MVMObject *base,
        MVMObject *type, MVMint64 offset);
