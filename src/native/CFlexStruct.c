#include "moarvm.h"

static MVMREPROps this_repr;

MVMREPROps * MVMCFlexStruct_initialize(MVMThreadContext *tc) {
    return &this_repr;
}
