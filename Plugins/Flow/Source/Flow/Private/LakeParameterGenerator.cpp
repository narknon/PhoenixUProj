#include "LakeParameterGenerator.h"

ULakeParameterGenerator::ULakeParameterGenerator() {
    this->WaterMaterials.AddDefaulted(1);
    this->WindWeight = 1.00f;
    this->bUseFixedWindVelocity = true;
    this->WindCoastFalloffDistance = 50.00f;
    this->Choppiness = 1.60f;
    this->WaveGravity = 9.81f;
    this->RandomSeed = 0;
    this->ShallowWaterAttenuation = 0.97f;
    this->WaveGravityVariance = 0.00f;
}

