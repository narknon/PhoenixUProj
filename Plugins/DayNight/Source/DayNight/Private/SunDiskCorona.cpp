#include "SunDiskCorona.h"

FSunDiskCorona::FSunDiskCorona() {
    this->MeshComponent = NULL;
    this->BaseMaterial = NULL;
    this->DynamicMaterial = NULL;
    this->BrightnessCurve = NULL;
    this->AlphaCurve = NULL;
    this->ScaleCurve = NULL;
    this->bEnabled = false;
}

