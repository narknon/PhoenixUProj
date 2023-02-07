#include "LerpVolumesLibrary.h"

ULerpVolumesLibrary::ULerpVolumesLibrary() {
    this->VolumeCollisionChannel = ECC_GameTraceChannel9;
    this->DefaultInterpolantsPriority = -1.00f;
}

