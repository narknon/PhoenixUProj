#include "FXFilter_RepeatMode.h"

UFXFilter_RepeatMode::UFXFilter_RepeatMode() {
    this->RepeatMode = EMultiFXRepeat::Restart;
    this->MaxCount = 1;
    this->bImmediate = false;
}

