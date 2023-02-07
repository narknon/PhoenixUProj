#include "SkyOnly.h"
#include "SkyOnlyComponent.h"

ASkyOnly::ASkyOnly() {
    this->SkyOnlyComponent = CreateDefaultSubobject<USkyOnlyComponent>(TEXT("SkyOnlyComponent"));
    this->bDualDirectionalLights = false;
    this->bEnabled = true;
}

