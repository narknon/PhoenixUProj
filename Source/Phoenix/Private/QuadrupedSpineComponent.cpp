#include "QuadrupedSpineComponent.h"

class UQuadrupedSpineComponent;

float UQuadrupedSpineComponent::GetInterpTimeAtSpeed(UQuadrupedSpineComponent* InSpineComponent, float InNormalizedSpeed) {
    return 0.0f;
}

UQuadrupedSpineComponent::UQuadrupedSpineComponent() {
    this->bAffectPose = true;
    this->SpineInterpTime = 0.65f;
    this->TurningFactor = 1.00f;
    this->BlendDurationIntoRootMotionAnim = 1.00f;
    this->BlendDurationOutOfRootMotionAnim = 0.35f;
    this->RootMotionAngleRemainingToStartBlendingIntoBent = 45.00f;
    this->RootMotionModifier = NULL;
}

