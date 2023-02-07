#include "AblPlayPostAkEvent.h"

UAblPlayPostAkEvent::UAblPlayPostAkEvent() {
    this->AkEvent = NULL;
    this->bStopWhenAttachedToDestroyed = false;
    this->bPlayerOnly = false;
    this->bPlayerInstigationOnly = false;
    this->EventToPostOnTaskEnd = NULL;
}

