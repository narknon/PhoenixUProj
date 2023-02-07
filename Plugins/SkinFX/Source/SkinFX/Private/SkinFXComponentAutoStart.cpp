#include "SkinFXComponentAutoStart.h"

USkinFXComponentAutoStart::USkinFXComponentAutoStart() {
    this->AutoStartEffect = NULL;
    this->InitialDelay = 0.00f;
    this->RepeatDelay = 0.00f;
    this->bRepeat = false;
    this->Timer = 0.00f;
    this->State = ESkinFXComponentAutoStartState::WaitingToStart;
}

