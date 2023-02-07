#include "AkMediaAsset.h"

UAkMediaAsset::UAkMediaAsset() {
    this->ID = 0;
    this->AutoLoad = true;
    this->Language = TEXT("SFX");
    this->CurrentMediaAssetData = NULL;
}

