#include "WorldInteractObject.h"
#include "CognitionStimuliSourceComponent.h"


AWorldInteractObject::AWorldInteractObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CognitionStimuliSource = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("CognitionStimuliSource"));
    this->AbilityClass = NULL;
    this->AbilitySpawnActorClass = NULL;
    this->InteractProperties = NULL;
}

