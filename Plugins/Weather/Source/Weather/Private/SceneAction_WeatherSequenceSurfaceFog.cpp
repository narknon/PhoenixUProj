#include "SceneAction_WeatherSequenceSurfaceFog.h"

USceneAction_WeatherSequenceSurfaceFog::USceneAction_WeatherSequenceSurfaceFog() {
    this->Type = ESurfaceFogType::Fog;
    this->bStretchToDuration = true;
}

