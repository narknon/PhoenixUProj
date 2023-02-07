#include "BTService_ListenForActorDamaged.h"

UBTService_ListenForActorDamaged::UBTService_ListenForActorDamaged() {
    this->bResetResultOnActivation = false;
    this->bResetResultOnDeactivation = false;
    this->bStopListeningAfterFirstSuccess = false;
}

