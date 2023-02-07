#include "MapOverland.h"

class UObject;
class UOverlandMapScreen;
class UTexture2D;

void UMapOverland::RemoveWayMarkerBP() {
}

UOverlandMapScreen* UMapOverland::GetMapScreenWidget() {
    return NULL;
}

void UMapOverland::DoFastTravel() {
}

void UMapOverland::CursorCallback(UTexture2D* Texture, UObject* Param) {
}

UMapOverland::UMapOverland() {
    this->FogMaskBlitter = NULL;
    this->Tiles[0] = NULL;
    this->Tiles[1] = NULL;
    this->Tiles[2] = NULL;
    this->Tiles[3] = NULL;
    this->Tiles[4] = NULL;
    this->Tiles[5] = NULL;
    this->Tiles[6] = NULL;
    this->Tiles[7] = NULL;
    this->Tiles[8] = NULL;
    this->Tiles[9] = NULL;
    this->Tiles[10] = NULL;
    this->Tiles[11] = NULL;
    this->Tiles[12] = NULL;
    this->Tiles[13] = NULL;
    this->Tiles[14] = NULL;
    this->Tiles[15] = NULL;
    this->Tiles[16] = NULL;
    this->Tiles[17] = NULL;
    this->Tiles[18] = NULL;
    this->Tiles[19] = NULL;
    this->Tiles[20] = NULL;
    this->Tiles[21] = NULL;
    this->Tiles[22] = NULL;
    this->Tiles[23] = NULL;
    this->Tiles[24] = NULL;
    this->Tiles[25] = NULL;
    this->Tiles[26] = NULL;
    this->Tiles[27] = NULL;
    this->Tiles[28] = NULL;
    this->Tiles[29] = NULL;
    this->Tiles[30] = NULL;
    this->Tiles[31] = NULL;
    this->Tiles[32] = NULL;
    this->Tiles[33] = NULL;
    this->Tiles[34] = NULL;
    this->Tiles[35] = NULL;
    this->Tiles[36] = NULL;
    this->Tiles[37] = NULL;
    this->Tiles[38] = NULL;
    this->Tiles[39] = NULL;
    this->Tiles[40] = NULL;
    this->Tiles[41] = NULL;
    this->Tiles[42] = NULL;
    this->Tiles[43] = NULL;
    this->Tiles[44] = NULL;
    this->Tiles[45] = NULL;
    this->Tiles[46] = NULL;
    this->Tiles[47] = NULL;
    this->Tiles[48] = NULL;
    this->Tiles[49] = NULL;
    this->Tiles[50] = NULL;
    this->Tiles[51] = NULL;
    this->Tiles[52] = NULL;
    this->Tiles[53] = NULL;
    this->Tiles[54] = NULL;
    this->Tiles[55] = NULL;
    this->Tiles[56] = NULL;
    this->Tiles[57] = NULL;
    this->Tiles[58] = NULL;
    this->Tiles[59] = NULL;
    this->Tiles[60] = NULL;
    this->Tiles[61] = NULL;
    this->Tiles[62] = NULL;
    this->Tiles[63] = NULL;
    this->MapWidget = NULL;
    this->MapBounds = NULL;
    this->RegionMaskBlitter = NULL;
    this->bIsFastTravelListShowingRegions = true;
    this->ZoomFactorTier1 = 0.10f;
    this->ZoomFactorTier2 = 0.30f;
    this->ZoomFactorTier3 = 0.50f;
    this->ZoomFactorTier4 = 0.70f;
    this->ZoomFactorTier5 = 0.90f;
    this->RegionSplineHeight = -4000.00f;
    this->DefaultIconScale = 4.00f;
    this->CursorScale = 20.00f;
    this->CursorScaleFactor = -30.00f;
    this->FogMaskTexture = NULL;
    this->RegionMaskTexture = NULL;
    this->RegionHighlightMaskTexture = NULL;
    this->AboveFogHeight = -1550.00f;
}

