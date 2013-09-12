MVMObject * MVM_native_bloballoc(MVMThreadContext *tc, MVMuint64 size);

MVMObject * MVM_native_blobptr(MVMThreadContext *tc, MVMObject *blob,
        MVMObject *type);

MVMObject * MVM_native_ptrcast(MVMThreadContext *tc, MVMObject *src,
        MVMObject *type, MVMint64 offset);

MVMuint64 MVM_native_sizeof(MVMThreadContext *tc, MVMObject *ptr);
