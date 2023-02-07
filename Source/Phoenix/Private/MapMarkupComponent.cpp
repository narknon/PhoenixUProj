#include "MapMarkupComponent.h"

bool UMapMarkupComponent::IsStairs() {
    return false;
}

bool UMapMarkupComponent::IsRoom() {
    return false;
}

bool UMapMarkupComponent::IsFloor() {
    return false;
}

TEnumAsByte<EMapRegionType> UMapMarkupComponent::GetType() {
    return MAP_REGION_TYPE_UNDEFINED;
}

UMapMarkupComponent::UMapMarkupComponent() {
    this->ShowBannerWhenEntering = false;
    this->Type = MAP_REGION_TYPE_UNDEFINED;
}

