#include "SceneRigStage.h"

USceneRigStage::USceneRigStage() {
    this->bEnableDefaultLighting = false;
    this->bShouldSimulatePhysics = true;
    this->OverrideEnvironmentPath = false;
    this->UseExportRadius = false;
    this->ExportRadius = 0.00f;
}

