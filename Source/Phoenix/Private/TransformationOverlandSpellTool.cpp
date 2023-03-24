#include "TransformationOverlandSpellTool.h"

ATransformationOverlandSpellTool::ATransformationOverlandSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpawnDelay = 0.25f;
    this->SpawnUpdateCount = 5;
    this->StartEffectDelay = 0.01f;
    this->HideDelay = 0.50f;
    this->RestoreDelay = 0.25f;
    this->SpawnHeightAdj = 0.00f;
    this->SpawnFacingCaster = false;
    this->RestoreMunitionDataAsset = NULL;
}

