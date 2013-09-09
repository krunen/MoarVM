#include "moarvm.h"
#include "native/ops.h"

MVMObject * MVM_native_ptrcast(MVMThreadContext *tc, MVMObject *type_obj,
        MVMObject *ptr_obj, MVMint64 offset) {
    void *ptr;

    switch (ptr_obj->st->REPR->ID) {
        case MVM_REPR_ID_CPointer:
            ptr = ((MVMCPointer *)ptr_obj)->body.ptr;
            break;
        case MVM_REPR_ID_CScalar:
            ptr = ((MVMCScalar*)ptr_obj)->body.ptr;
            break;
        case MVM_REPR_ID_CArray:
            ptr = ((MVMCArray *)ptr_obj)->body.ptr;
            break;
        case MVM_REPR_ID_CStruct:
            ptr = ((MVMCStruct *)ptr_obj)->body.ptr;
            break;
        case MVM_REPR_ID_CUnion:
            ptr = ((MVMCUnion *)ptr_obj)->body.ptr;
            break;
        case MVM_REPR_ID_CFlexibleStruct:
            ptr = ((MVMCFlexibleStruct *)ptr_obj)->body.ptr;
            break;
        default:
            MVM_exception_throw_adhoc(tc, "cannot cast from non-pointer repr %"
                    PRIu32, type_obj->st->REPR->ID);
    }

    ptr = (char *)ptr + offset;

    switch (type_obj->st->REPR->ID) {
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
                    PRIu32, type_obj->st->REPR->ID);
    }
}
