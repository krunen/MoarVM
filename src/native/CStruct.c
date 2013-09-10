#include "moarvm.h"

static MVMREPROps this_repr;

MVMREPROps * MVMCStruct_initialize(MVMThreadContext *tc) {
    return &this_repr;
}
