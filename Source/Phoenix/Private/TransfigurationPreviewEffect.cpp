#include "TransfigurationPreviewEffect.h"

class AActor;


void ATransfigurationPreviewEffect::OnTargetActorDestroyed(AActor* InDestroyedActor) {
}


ATransfigurationPreviewEffect::ATransfigurationPreviewEffect(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CanPlaceObject = false;
    this->TargetActor = NULL;
    this->TargetActorCopy = NULL;
}

