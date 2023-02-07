#include "SceneActionState_WeatherGeneric.h"

USceneActionState_WeatherGeneric::USceneActionState_WeatherGeneric() {
    this->CachedTime = -1.00f;
    this->CachedDuration = -1.00f;
    this->bCachedEnabled = false;
    this->bCachedInsideInterval = false;
}

