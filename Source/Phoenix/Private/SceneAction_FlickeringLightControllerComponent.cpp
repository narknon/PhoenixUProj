#include "SceneAction_FlickeringLightControllerComponent.h"

USceneAction_FlickeringLightControllerComponent::USceneAction_FlickeringLightControllerComponent() {
    this->Settings = NULL;
    this->StartOffset = 0.00f;
    this->DurationScale = 1.00f;
    this->bRandomizeStartOffset = false;
}

