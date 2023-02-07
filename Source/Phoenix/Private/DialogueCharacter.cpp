#include "DialogueCharacter.h"
#include "CharacterStateComponent.h"

ADialogueCharacter::ADialogueCharacter() {
    this->ObjectStateComponent = CreateDefaultSubobject<UCharacterStateComponent>(TEXT("CharacterStateComponent"));
}

