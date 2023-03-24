#include "SkinFXDefinition.h"

ASkinFXDefinition::ASkinFXDefinition(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Priority = ESkinFXEffectPriority::Normal;
    this->SwapType = ESkinFXEffectSwapType::UsePermutedMaterials;
    this->bAllowInBackground = true;
    this->TimeSource = ESkinFXEffectTimeSource::Actor;
    this->bDestroyActorWhenDone = false;
    this->bFullRetriggerOnRestart = false;
    this->bShowSwapErrors = false;
}

