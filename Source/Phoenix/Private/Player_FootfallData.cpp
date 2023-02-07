#include "Player_FootfallData.h"

FPlayer_FootfallData::FPlayer_FootfallData() {
    this->PingDistance = 0.00f;
    this->MinSpeed = 0.00f;
    this->MaxSpeed = 0.00f;
    this->MinRange = 0.00f;
    this->MaxRange = 0.00f;
    this->Intensity = EGameEvent_Intensity::None;
    this->MinDisillusionmentRange = 0.00f;
    this->MaxDisillusionmentRange = 0.00f;
    this->DisillusionmentIntensity = EGameEvent_Intensity::None;
}

