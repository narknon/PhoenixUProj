#include "TransfigurationObjectBase.h"
#include "CognitionStimuliSourceComponent.h"

ATransfigurationObjectBase::ATransfigurationObjectBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CogSourceComponent = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("CogStimuliSource"));
    this->bIsPreviewActor = false;
}

