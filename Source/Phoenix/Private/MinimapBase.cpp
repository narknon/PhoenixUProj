#include "MinimapBase.h"

class UMapIconInstance;
class UTexture2D;

void UMinimapBase::ShowOutline(UMapIconInstance* Icon) {
}


void UMinimapBase::SetSize(float Size) {
}

void UMinimapBase::SetPlayerPositionTextureSpaceEvent(FVector2D pPlayerLocation) {
}


void UMinimapBase::SetPlayerPosition(FVector pPlayerPosition) {
}

void UMinimapBase::SetPathPulseVisibility(float PulseVisibility) {
}

void UMinimapBase::SetPathPulseSpeed(float Speed) {
}

void UMinimapBase::SetOpacity(float Alpha) {
}

void UMinimapBase::SetMiniMapSize(float Size, float ZoomTime) {
}

void UMinimapBase::SetMaterialTexture(const FString& TextureParameter, UTexture2D* Texture) {
}


void UMinimapBase::SetIntrusionColor(FLinearColor Color) {
}

void UMinimapBase::SetIconDistanceScale(float IconDistanceScale) {
}

void UMinimapBase::SetColorByName(const FString& ParameterName, FLinearColor Color) {
}

void UMinimapBase::PulseCircleIcon(UMapIconInstance* Icon) {
}

void UMinimapBase::OverrideLevelBounds(FVector2D TopLeft, FVector2D BottomRight) {
}

bool UMinimapBase::IsPointInBounds(FVector2D Point, FVector2D TL, FVector2D BR) {
    return false;
}

FVector2D UMinimapBase::GetWorldToTextureScale() {
    return FVector2D{};
}

void UMinimapBase::GetVisibleBoundsInPixels(FVector2D& TL, FVector2D& BR) {
}

void UMinimapBase::GetVisibleBounds(FVector2D& TL, FVector2D& BR) {
}

FVector2D UMinimapBase::GetTopLeftPadded() {
    return FVector2D{};
}

FVector UMinimapBase::GetPlayerLocation() {
    return FVector{};
}

FVector2D UMinimapBase::GetOnScreenTextureArea() {
    return FVector2D{};
}

float UMinimapBase::GetMiniMapZoomSize() {
    return 0.0f;
}

float UMinimapBase::GetMiniMapSize() {
    return 0.0f;
}

float UMinimapBase::GetMiniMapInitialSize() {
    return 0.0f;
}

FVector2D UMinimapBase::GetMapToTextureRatio() {
    return FVector2D{};
}

FVector2D UMinimapBase::GetMapMultiplier() {
    return FVector2D{};
}

void UMinimapBase::GetBoundsForTextureSpaceSubSection(FVector WorldPosition, FVector2D& TL, FVector2D& BR, float& AvgMultiplier) {
}

FVector2D UMinimapBase::GetBottomRightPadded() {
    return FVector2D{};
}

void UMinimapBase::FadeInMissionIcon(UMapIconInstance* Icon) {
}

void UMinimapBase::FadeInCircleIcon(UMapIconInstance* Icon) {
}

FVector2D UMinimapBase::ConvertFromWorldSpaceToTextureSpaceSubSection(FVector WorldPosition) {
    return FVector2D{};
}

void UMinimapBase::CalculateScale() {
}

UMinimapBase::UMinimapBase() : UUserWidget(FObjectInitializer::Get()) {
    this->InSearchAreaState = false;
    this->MinYElevationDist = 300.00f;
    this->MinYElevationDistHogwarts = 300.00f;
    this->MaxXElevationDist = 20000.00f;
    this->MinYElevationDistSquared = 250000.00f;
    this->MaxXElevationDistSquared = 400000000.00f;
    this->ElevationBuffer = 50.00f;
    this->ElevationBufferSquared = 2500.00f;
    this->MiniMapParameters = NULL;
    this->MapVirtualTexture = NULL;
    this->MapRegularVirtualTexture = NULL;
    this->MapNoFlyVirtualTexture = NULL;
    this->MapRenderTarget = NULL;
    this->MapRenderTargetNoFly = NULL;
    this->Material = NULL;
    this->MaterialDynamic = NULL;
}

