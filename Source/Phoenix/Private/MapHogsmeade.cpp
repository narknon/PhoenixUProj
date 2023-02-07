#include "MapHogsmeade.h"

class UHogsmeadeMapScreen;

void UMapHogsmeade::RemoveWayMarkerBP() {
}

UHogsmeadeMapScreen* UMapHogsmeade::GetMapScreenWidget() {
    return NULL;
}

void UMapHogsmeade::DoFastTravel() {
}

UMapHogsmeade::UMapHogsmeade() {
    this->MapWidget = NULL;
    this->ZoomFactorTier1 = 0.10f;
    this->ZoomFactorTier2 = 0.30f;
    this->ZoomFactorTier3 = 0.50f;
    this->ZoomFactorTier4 = 0.70f;
    this->ZoomFactorTier5 = 0.90f;
    this->DefaultIconScale = 4.00f;
    this->CursorScale = 1.00f;
    this->CursorScaleFactor = -2.00f;
}

