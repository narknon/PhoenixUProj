#include "TransfigurationObjectStationBase.h"
#include "CognitionStimuliSourceComponent.h"

ATransfigurationObjectStationBase::ATransfigurationObjectStationBase() {
    this->CogSourceComponent = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("CogStimuliSource"));
}

