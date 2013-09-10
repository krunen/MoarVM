#include "moarvm.h"

static MVMREPROps this_repr;

MVMREPROps * MVMCUnion_initialize(MVMThreadContext *tc) {
    return &this_repr;
}
