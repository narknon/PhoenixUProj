#include "SceneAction_WeatherSequenceCameraMesh.h"

USceneAction_WeatherSequenceCameraMesh::USceneAction_WeatherSequenceCameraMesh() {
    this->SetMaterialOutdoors = TEXT("Outdoors");
    this->bHideIndoors = true;
    this->bSetOutdoorsValue = true;
}

