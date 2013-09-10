#include "moarvm.h"

static MVMREPROps this_repr;

MVMREPROps * MVMCFlexibleStruct_initialize(MVMThreadContext *tc) {
    return &this_repr;
}
