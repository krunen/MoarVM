#include "moarvm.h"
#include "native/ops.h"

MVMObject * MVM_native_ptrcast(MVMThreadContext *tc, MVMObject *type_obj,
        MVMObject *ptr_obj) {
    MVMuint32 ptr_id  = REPR(ptr_obj)->ID;
    MVMuint32 type_id = REPR(type_obj)->ID;
    void *ptr;

    switch (ptr_id) {
        case MVM_REPR_ID_CPointer:
            ptr = ((MVMCPointer *)ptr_obj)->body.cobj;
            break;
        case MVM_REPR_ID_CScalar:
            ptr = ((MVMCScalar *)ptr_obj)->body.cobj;
            break;
        case MVM_REPR_ID_CArray:
            ptr = ((MVMCArray *)ptr_obj)->body.cobj;
            break;
        case MVM_REPR_ID_CStruct:
            ptr = ((MVMCStruct *)ptr_obj)->body.cobj;
            break;
        case MVM_REPR_ID_CUnion:
            ptr = ((MVMCUnion *)ptr_obj)->body.cobj;
            break;
        case MVM_REPR_ID_CFlexibleStruct:
            ptr = ((MVMCFlexibleStruct *)ptr_obj)->body.cobj;
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
            break;

        default:
            MVM_exception_throw_adhoc(tc, "cannot cast to non-pointer repr %"
                    PRIu32, type_id);
    }
}
