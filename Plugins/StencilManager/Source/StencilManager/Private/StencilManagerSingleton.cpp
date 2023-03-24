#include "StencilManagerSingleton.h"

class UObject;

void AStencilManagerSingleton::SetStencilPlayerNearFadeDisable(UObject* WorldContextObject, bool bPlayerNearFadeDisable) {
}

void AStencilManagerSingleton::SetStencilBlend(UObject* WorldContextObject, float blendVal) {
}

void AStencilManagerSingleton::SetOutdoorsDaytimeBoost(UObject* WorldContextObject, float boostVal) {
}

AStencilManagerSingleton::AStencilManagerSingleton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Settings = NULL;
    this->ExternalControls = NULL;
    this->StencilBlend = 1.00f;
    this->bUpdatedStencilBlend = false;
    this->bConsoleDisableStencil = false;
    this->bDisableStencil = false;
}

