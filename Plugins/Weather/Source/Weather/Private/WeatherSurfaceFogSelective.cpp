#include "WeatherSurfaceFogSelective.h"

class USceneComponent;

void AWeatherSurfaceFogSelective::SetComponentToShowHide(USceneComponent* SceneComponent, bool bIncludeChildren) {
}

AWeatherSurfaceFogSelective::AWeatherSurfaceFogSelective() {
    this->OnlyShowHide = NULL;
    this->bOnlyShowHideIncludeChildren = false;
}

