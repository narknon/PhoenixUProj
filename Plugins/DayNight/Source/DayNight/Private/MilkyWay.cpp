#include "MilkyWay.h"

FMilkyWay::FMilkyWay() {
    this->Mesh = NULL;
    this->MeshComponent = NULL;
    this->BaseBrightness = 0.00f;
    this->Contrast = 0.00f;
    this->Desaturation = 0.00f;
    this->SolidColorBlend = 0.00f;
    this->AlphaEdgePower = 0.00f;
    this->MoonBrightnessModifier = NULL;
    this->MoonFadePower = NULL;
    this->bCorrection = false;
}

