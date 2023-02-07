#include "WorldInteractObject.h"
#include "CognitionStimuliSourceComponent.h"


AWorldInteractObject::AWorldInteractObject() {
    this->CognitionStimuliSource = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("CognitionStimuliSource"));
    this->AbilityClass = NULL;
    this->AbilitySpawnActorClass = NULL;
    this->InteractProperties = NULL;
}

