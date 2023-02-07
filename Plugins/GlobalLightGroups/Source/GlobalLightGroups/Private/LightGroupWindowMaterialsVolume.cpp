#include "LightGroupWindowMaterialsVolume.h"
#include "LightGroupComponent.h"

void ALightGroupWindowMaterialsVolume::RefreshBuildResults() {
}

ALightGroupWindowMaterialsVolume::ALightGroupWindowMaterialsVolume() {
    this->LightGroup = CreateDefaultSubobject<ULightGroupComponent>(TEXT("LightGroup"));
    this->WindowGroupMaterialParameter = TEXT("WindowLightGroup");
}

