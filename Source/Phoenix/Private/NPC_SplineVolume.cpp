#include "NPC_SplineVolume.h"

ANPC_SplineVolume::ANPC_SplineVolume() {
    this->bIdle = false;
    this->IdleInterval = -1.00f;
    this->IdleIntervalDeviation = 0.00f;
    this->VolumeMoveScale = 1.00f;
    this->bApplyVolumeSpeed = false;
    this->MinVolumeSpeed = 100.00f;
    this->MaxVolumeSpeed = 300.00f;
    this->bChangeSpeed = false;
    this->MinSpeed = 100.00f;
    this->MaxSpeed = 300.00f;
    this->bChangeScurrySpeed = false;
    this->ScurryMinSpeed = 100.00f;
    this->ScurryMaxSpeed = 300.00f;
}

