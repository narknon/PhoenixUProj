#include "TurnDirectionNavMeshCheckSettings.h"

FTurnDirectionNavMeshCheckSettings::FTurnDirectionNavMeshCheckSettings() {
    this->bDoNavMeshCheck = false;
    this->bForceSuccessIfMount = false;
    this->TurnDirection = ECreatureNavMeshTurnDirection::Left;
    this->bIncActorRadius = false;
    this->TurnDiameterScalar = 0.00f;
    this->TurnLengthScalar = 0.00f;
    this->BoxExtentsZ = 0.00f;
    this->bDebugDrawing = false;
}

