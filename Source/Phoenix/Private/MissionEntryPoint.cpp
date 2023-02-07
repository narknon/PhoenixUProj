#include "MissionEntryPoint.h"
#include "MissionEntryPointEffectComponent.h"

AMissionEntryPoint::AMissionEntryPoint() {
    this->m_ringRadius = 0.00f;
    this->RingEffectComponent = CreateDefaultSubobject<UMissionEntryPointEffectComponent>(TEXT("RingEffect"));
    this->CalloutLocator = NULL;
    this->CognitionStimuliSource = NULL;
}

