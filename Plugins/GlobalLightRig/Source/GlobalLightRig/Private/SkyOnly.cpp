#include "SkyOnly.h"
#include "SkyOnlyComponent.h"

ASkyOnly::ASkyOnly(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SkyOnlyComponent = CreateDefaultSubobject<USkyOnlyComponent>(TEXT("SkyOnlyComponent"));
    this->bDualDirectionalLights = false;
    this->bEnabled = true;
}

