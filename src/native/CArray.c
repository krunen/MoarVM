#include "moarvm.h"

static MVMREPROps this_repr;

MVMREPROps * MVMCArray_initialize(MVMThreadContext *tc) {
    return &this_repr;
}
