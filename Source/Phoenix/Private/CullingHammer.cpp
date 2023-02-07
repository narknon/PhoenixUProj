#include "CullingHammer.h"
#include "Components/PostProcessComponent.h"
#include "Components/StaticMeshComponent.h"

void ACullingHammer::RebuildBlocker() {
}

void ACullingHammer::EnableCrackFillerPostProcess(bool bEnable) {
}

ACullingHammer::ACullingHammer() {
    this->WorldBoundsScale = 1.00f;
    this->BlockerTranslucentSortPriority = 0;
    this->bUseRadius = false;
    this->bCreateOnBeginPlay = true;
    this->bEnableBlockerObject = false;
    this->ObjectBoundsScalePercent = 110.00f;
    this->bObjectBoundsScalePercent = false;
    this->bEnableCrackFiller = false;
    this->BlockerComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockerObject"));
    this->CrackFillerPostProcess = CreateDefaultSubobject<UPostProcessComponent>(TEXT("CrackFillerPostProcessComponent"));
}

