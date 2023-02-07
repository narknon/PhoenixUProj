#include "SimpleBlobShadowDecalComponent.h"

USimpleBlobShadowDecalComponent::USimpleBlobShadowDecalComponent() {
    this->Scale = 1.41f;
    this->ZTweak = 0.00f;
    this->MaxDrawDistance = 12500.00f;
    this->InAirFadeDistanceStart = 5.00f;
    this->InAirFadeDistance = 50.00f;
    this->MinOpacityDistance = 300.00f;
    this->MinOpacity = 0.65f;
    this->MaxOpacityDistance = 1700.00f;
    this->MaxOpacity = 1.00f;
    this->bUseBoundsCenter = false;
    this->DecalMID = NULL;
    this->bEnabled = true;
}

