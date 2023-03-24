#include "ConjurationPreviewEffect.h"









float AConjurationPreviewEffect::GetSpawnPercent() {
    return 0.0f;
}

AConjurationPreviewEffect::AConjurationPreviewEffect(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpawnTimeLimit = 0.20f;
    this->TargetPreviewActor = NULL;
    this->SpawnState = EConjurationSpawnState::None;
}

