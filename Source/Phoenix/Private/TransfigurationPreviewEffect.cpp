#include "TransfigurationPreviewEffect.h"

class AActor;


void ATransfigurationPreviewEffect::OnTargetActorDestroyed(AActor* InDestroyedActor) {
}


ATransfigurationPreviewEffect::ATransfigurationPreviewEffect() {
    this->CanPlaceObject = false;
    this->TargetActor = NULL;
    this->TargetActorCopy = NULL;
}

