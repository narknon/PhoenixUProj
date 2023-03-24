#include "SimpleInteractObject.h"
#include "CognitionStimuliSourceComponent.h"

void ASimpleInteractObject::PlayDialogue() {
}


UClass* ASimpleInteractObject::GetAbilityClass_Implementation() {
    return NULL;
}

ASimpleInteractObject::ASimpleInteractObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CognitionStimuliSource = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("CognitionStimuliSource"));
    this->AbilityClass = NULL;
    this->bPartialBody = false;
    this->AbilitySpawnActorClass = NULL;
    this->InteractProperties = NULL;
    this->PlayDialogueAfterInteractTime = -1.00f;
}

