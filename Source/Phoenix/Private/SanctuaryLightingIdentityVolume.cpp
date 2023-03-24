#include "SanctuaryLightingIdentityVolume.h"
#include "Components/BoxComponent.h"
#include "Components/PostProcessComponent.h"
#include "BlendableGlobalLightingComponent.h"
#include "RenderSettingsComponent.h"

ASanctuaryLightingIdentityVolume::ASanctuaryLightingIdentityVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Priority = 10.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bUnbounded = false;
    this->bEnableTransitionExposureSpeedUp = true;
    this->TransitionExposureSpeed = 20.00f;
    this->bEnableTransitionFogHistoryRemoval = true;
    this->TransitionFogHistoryWeight = 0.00f;
    this->bEnableDayNight = true;
    this->bEnableGlobalLighting = true;
    this->bEnableRenderSettings = true;
    this->bEnablePostProcess = true;
    this->BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    this->GlobalLightingComponent = CreateDefaultSubobject<UBlendableGlobalLightingComponent>(TEXT("GlobalLightingComponent"));
    this->RenderSettingsComponent = CreateDefaultSubobject<URenderSettingsComponent>(TEXT("RenderSettingsComponent"));
    this->PostProcessComponent = CreateDefaultSubobject<UPostProcessComponent>(TEXT("PostProcessComponent"));
    this->PrevGlobalLightingComponent = NULL;
    this->PrevRenderSettingsComponent = NULL;
    this->PrevPostProcessComponent = NULL;
    this->TransitionGlobalLightingComponent = NULL;
    this->TransitionPostProcessComponent = NULL;
}

