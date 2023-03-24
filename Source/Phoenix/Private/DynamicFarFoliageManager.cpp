#include "DynamicFarFoliageManager.h"

void ADynamicFarFoliageManager::MainProcessIteration(float DeltaTime) {
}

ADynamicFarFoliageManager::ADynamicFarFoliageManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HostInstancedFoliageActor = NULL;
    this->TotalInstancesCount = 0;
}

