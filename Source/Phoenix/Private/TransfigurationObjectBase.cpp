#include "TransfigurationObjectBase.h"
#include "CognitionStimuliSourceComponent.h"

ATransfigurationObjectBase::ATransfigurationObjectBase() {
    this->CogSourceComponent = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("CogStimuliSource"));
    this->bIsPreviewActor = false;
}

