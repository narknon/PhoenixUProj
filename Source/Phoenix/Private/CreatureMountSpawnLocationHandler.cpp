#include "CreatureMountSpawnLocationHandler.h"

FCreatureMountSpawnLocationHandler::FCreatureMountSpawnLocationHandler() {
    this->FastMountBoxSizeX = 0.00f;
    this->RadiusBuffer = 0.00f;
    this->SweepStepSize = 0.00f;
    this->StepCountPerUpdate = 0;
    this->StepInc = 0.00f;
    this->StepStart = 0.00f;
    this->StepEnd = 0.00f;
    this->bSpawnAtRiderZ = false;
    this->bDrawDebug = false;
}

