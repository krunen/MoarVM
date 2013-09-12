#include "moarvm.h"

static MVMREPROps this_repr;

MVMREPROps * MVMCPointer_initialize(MVMThreadContext *tc) {
    return &this_repr;
}

