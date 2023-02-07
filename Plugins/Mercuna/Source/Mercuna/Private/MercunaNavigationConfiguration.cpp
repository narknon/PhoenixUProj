#include "MercunaNavigationConfiguration.h"

FMercunaNavigationConfiguration::FMercunaNavigationConfiguration() {
    this->MaxPitch = 0.00f;
    this->MaxRoll = 0.00f;
    this->RollSensitivity = 0.00f;
    this->MoveOnlyInLookDirection = false;
    this->StopAtDestination = false;
    this->HeightChangePenalty = 0.00f;
    this->SmoothPaths = false;
    this->LookAheadTime = 0.00f;
    this->RollAnticipationTime = 0.00f;
}

