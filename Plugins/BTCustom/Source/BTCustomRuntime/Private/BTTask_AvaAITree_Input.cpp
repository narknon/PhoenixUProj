#include "BTTask_AvaAITree_Input.h"

class UInputComponent;

void UBTTask_AvaAITree_Input::SetManagedContext_Implementation(const FInputContextWithType InContext, const bool bFlag) {
}

void UBTTask_AvaAITree_Input::PlayerInputComponentCreated(const UInputComponent* InputComponent) {
}

void UBTTask_AvaAITree_Input::PlayerInputComponentAboutToBeDestroyed() {
}

bool UBTTask_AvaAITree_Input::GetManagedContext_Implementation(const FInputContextWithType InContext) {
    return false;
}

UBTTask_AvaAITree_Input::UBTTask_AvaAITree_Input() {
    this->FacialAnimationPriority = EManagedFacialAnimationPriority::MECHANIC;
}

