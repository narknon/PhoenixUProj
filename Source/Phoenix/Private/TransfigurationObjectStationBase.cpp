#include "TransfigurationObjectStationBase.h"
#include "CognitionStimuliSourceComponent.h"

ATransfigurationObjectStationBase::ATransfigurationObjectStationBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CogSourceComponent = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("CogStimuliSource"));
}

