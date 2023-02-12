#include "AkSpatialAudioSettings.h"

FAkSpatialAudioSettings::FAkSpatialAudioSettings() {
    this->MaxSoundPropagationDepth = 0;
    this->MovementThreshold = 0.00f;
    this->NumberOfPrimaryRays = 0;
    this->ReflectionOrder = 0;
    this->MaximumPathLength = 0.00f;
    this->CPULimitPercentage = 0.00f;
    this->EnableDiffractionOnReflections = false;
    this->EnableGeometricDiffractionAndTransmission = false;
    this->CalcEmitterVirtualPosition = false;
    this->UseObstruction = false;
    this->UseOcclusion = false;
}

