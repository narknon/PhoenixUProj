#include "LakeParameterSimpleGenerator.h"

ULakeParameterSimpleGenerator::ULakeParameterSimpleGenerator() {
    this->NumWaves = 16;
    this->Randomness = 0.00f;
    this->MinWavelength = 521.00f;
    this->MaxWavelength = 6000.00f;
    this->WavelengthFalloff = 2.00f;
    this->MinAmplitude = 4.00f;
    this->MaxAmplitude = 80.00f;
    this->AmplitudeFalloff = 2.00f;
    this->DirectionAngularSpreadDeg = 20.00f;
}

