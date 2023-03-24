#include "LightGroupWindowMaterialsVolume.h"
#include "LightGroupComponent.h"

void ALightGroupWindowMaterialsVolume::RefreshBuildResults() {
}

ALightGroupWindowMaterialsVolume::ALightGroupWindowMaterialsVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LightGroup = CreateDefaultSubobject<ULightGroupComponent>(TEXT("LightGroup"));
    this->WindowGroupMaterialParameter = TEXT("WindowLightGroup");
}

