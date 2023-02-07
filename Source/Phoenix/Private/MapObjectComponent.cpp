#include "MapObjectComponent.h"

UMapObjectComponent::UMapObjectComponent() {
    this->LimitCamera = false;
    this->StartRadius = 30000.00f;
    this->StartPitch = 0.00f;
    this->StartYaw = 0.00f;
    this->StartElevation = 0.00f;
    this->HasMaterialInstance = false;
    this->ParentComponent = TEXT("None");
    this->ChildComponent = TEXT("None");
    this->UpComponent = TEXT("None");
    this->DownComponent = TEXT("None");
    this->LeftComponent = TEXT("None");
    this->RightComponent = TEXT("None");
    this->AnimationSpeed = 0.50f;
    this->AnimationBounce = 0.20f;
    this->AnimationBounceFalloff = 0.05f;
    this->MaxAnimationScale = 1.00f;
    this->MinAnimationScale = 0.01f;
}

