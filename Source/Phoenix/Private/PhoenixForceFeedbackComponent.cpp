#include "PhoenixForceFeedbackComponent.h"

void UPhoenixForceFeedbackComponent::SetCadenceMultiplier(float NewCadenceMultiplier) {
}

UPhoenixForceFeedbackComponent::UPhoenixForceFeedbackComponent() : UForceFeedbackComponent(FObjectInitializer::Get()) {
    this->CadenceMultiplier = 1.00f;
}

