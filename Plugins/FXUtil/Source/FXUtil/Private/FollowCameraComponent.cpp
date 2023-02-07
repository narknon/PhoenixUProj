#include "FollowCameraComponent.h"

UFollowCameraComponent::UFollowCameraComponent() {
    this->FollowType = EFollowCameraType::FCT_FULL;
    this->ZValue = 0.00f;
}

