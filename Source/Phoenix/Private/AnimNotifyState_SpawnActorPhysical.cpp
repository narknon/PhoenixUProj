#include "AnimNotifyState_SpawnActorPhysical.h"

UAnimNotifyState_SpawnActorPhysical::UAnimNotifyState_SpawnActorPhysical() {
    this->SpawnActorClass = NULL;
    this->StaticMeshOverride = NULL;
    this->bTurnPhysicalAtEnd = false;
    this->ActorLifeSpan = 1.00f;
}

