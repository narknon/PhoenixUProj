#include "WeatherSurfaceFogSelective.h"

class USceneComponent;

void AWeatherSurfaceFogSelective::SetComponentToShowHide(USceneComponent* SceneComponent, bool bIncludeChildren) {
}

AWeatherSurfaceFogSelective::AWeatherSurfaceFogSelective(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OnlyShowHide = NULL;
    this->bOnlyShowHideIncludeChildren = false;
}

