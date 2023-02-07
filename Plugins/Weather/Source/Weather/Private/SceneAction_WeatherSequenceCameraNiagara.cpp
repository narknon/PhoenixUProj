#include "SceneAction_WeatherSequenceCameraNiagara.h"

USceneAction_WeatherSequenceCameraNiagara::USceneAction_WeatherSequenceCameraNiagara() {
    this->SetOutdoors = TEXT("SpawnRateMultiply");
    this->bSetOutdoorsValue = true;
    this->bHideIndoors = true;
}

