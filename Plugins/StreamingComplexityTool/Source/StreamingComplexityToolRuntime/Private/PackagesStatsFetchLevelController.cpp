#include "PackagesStatsFetchLevelController.h"

APackagesStatsFetchLevelController::APackagesStatsFetchLevelController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PackageStatsCaptureSettings = NULL;
    this->WorldStructureGenerator = NULL;
}

