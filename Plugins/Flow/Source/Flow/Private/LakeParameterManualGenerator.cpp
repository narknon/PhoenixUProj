#include "LakeParameterManualGenerator.h"

ULakeParameterManualGenerator::ULakeParameterManualGenerator() {
    this->OverallWeight = 1.00f;
    this->ComponentsPerOctave = 8;
    this->WaveDirectionVariance = 60.00f;
    this->bEnable000025 = true;
    this->Power000025 = -7.00f;
    this->bEnable000050 = true;
    this->Power000050 = -5.60f;
    this->bEnable000100 = true;
    this->Power000100 = -3.90f;
    this->bEnable000200 = true;
    this->Power000200 = -3.10f;
    this->bEnable000400 = true;
    this->Power000400 = -2.40f;
    this->bEnable000800 = true;
    this->Power000800 = -1.60f;
    this->bEnable001600 = true;
    this->Power001600 = -0.90f;
    this->bEnable003200 = true;
    this->Power003200 = -0.20f;
    this->bEnable006400 = true;
    this->Power006400 = 0.30f;
    this->bEnable012800 = true;
    this->Power012800 = 0.10f;
    this->bEnable025600 = true;
    this->Power025600 = -3.20f;
    this->bEnable051200 = true;
    this->Power051200 = -7.00f;
}

