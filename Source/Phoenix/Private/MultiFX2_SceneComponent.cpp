#include "MultiFX2_SceneComponent.h"
#include "Components/SceneComponent.h"

UMultiFX2_SceneComponent::UMultiFX2_SceneComponent() {
    this->SpawnSceneComponentClass = USceneComponent::StaticClass();
    this->bAttached = false;
    this->bIgnoreDeactivate = false;
}

