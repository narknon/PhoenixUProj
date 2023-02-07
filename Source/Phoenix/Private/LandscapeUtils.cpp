#include "LandscapeUtils.h"

class ULandscapeHeightfieldCollisionComponent;
class UPhysicalMaterial;

void ULandscapeUtils::LogLandscapeComponentLayerInfoData(ULandscapeHeightfieldCollisionComponent* LandColComponent) {
}

TArray<FLayerInfoWeight> ULandscapeUtils::LineTraceForLayerInfoWeight(FVector Start, FVector End) {
    return TArray<FLayerInfoWeight>();
}

float ULandscapeUtils::GetWetnessFromLayerInfoData(ULandscapeHeightfieldCollisionComponent* LandColComponent, const FVector& InLocation, const TArray<FString>& InWetnessLayerInfoNames, UPhysicalMaterial*& OutPhysMaterial) {
    return 0.0f;
}

TArray<FLayerInfoWeight> ULandscapeUtils::GetLandscapeComponentLayerInfoData(ULandscapeHeightfieldCollisionComponent* LandColComponent) {
    return TArray<FLayerInfoWeight>();
}

void ULandscapeUtils::ClearLandscapeComponentLayerInfoData() {
}

ULandscapeUtils::ULandscapeUtils() {
}

