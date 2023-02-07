#include "AISenseConfig_GameEvent.h"
#include "AISense_GameEvent.h"

UAISenseConfig_GameEvent::UAISenseConfig_GameEvent() {
    this->Implementation = UAISense_GameEvent::StaticClass();
    this->FootfallDataAsset = NULL;
}

