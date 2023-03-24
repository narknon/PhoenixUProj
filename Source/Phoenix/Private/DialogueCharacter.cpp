#include "DialogueCharacter.h"
#include "CharacterStateComponent.h"

ADialogueCharacter::ADialogueCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ObjectStateComponent = CreateDefaultSubobject<UCharacterStateComponent>(TEXT("CharacterStateComponent"));
}

