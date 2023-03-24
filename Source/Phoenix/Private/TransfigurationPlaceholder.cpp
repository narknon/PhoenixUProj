#include "TransfigurationPlaceholder.h"

ATransfigurationPlaceholder::ATransfigurationPlaceholder(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InitialColor = ETransfigurationInitialColor::Default;
    this->bOverride_StreamingPriority = false;
    this->StreamingPriority = EStreamingPlaceholderPriority::Normal;
    this->UID = 0;
    this->SignedUID = 0;
    this->SpawnedActor = NULL;
}

