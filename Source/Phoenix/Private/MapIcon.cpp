#include "MapIcon.h"
#include "MapIconInstance.h"

void UMapIcon::StopAnimationAndChain(EMapIconState NextState) {
}

void UMapIcon::StopAnimation() {
}

void UMapIcon::SetTargetScale(float Scale) {
}

void UMapIcon::SetTargetColor(FLinearColor pTargetColor) {
}

void UMapIcon::SetState(EMapIconState IconState, bool SaveState) {
}

void UMapIcon::SetStartingScale(float Scale) {
}

void UMapIcon::SetScale(float ScaleIn) {
}

void UMapIcon::SetIconVisibility(bool pVisbility) {
}

void UMapIcon::SetIconPriority(int32 Priority) {
}

void UMapIcon::SetIconFlags(int32 flags) {
}

void UMapIcon::SetIconBadgeVisibility(bool pVisbility) {
}

void UMapIcon::SetColor(FLinearColor ColorIn) {
}

void UMapIcon::SetBadgeName(const FString& pBadgeName) {
}

bool UMapIcon::IsStopping() {
    return false;
}

bool UMapIcon::IsBadgeStopping() {
    return false;
}

float UMapIcon::GetTargetScale() {
    return 0.0f;
}

TEnumAsByte<EMapIconState> UMapIcon::GetState() {
    return MAP_ICON_STATE_HOVER;
}

float UMapIcon::GetStartingScale() {
    return 0.0f;
}

int32 UMapIcon::GetIconPriority() {
    return 0;
}

int32 UMapIcon::GetIconFlags() {
    return 0;
}

TEnumAsByte<EMapFadeState> UMapIcon::GetFadeState() {
    return MAP_FADE_STATE_IDLE;
}

FVector UMapIcon::GetBeaconWorldPosition() {
    return FVector{};
}

EBeaconType UMapIcon::GetBeaconType() {
    return EBeaconType::BEACONTYPE_NONE;
}

FString UMapIcon::GetBeaconName() {
    return TEXT("");
}

FString UMapIcon::GetBeaconIcon() {
    return TEXT("");
}

FString UMapIcon::GetBeaconFastTravelLocationID() {
    return TEXT("");
}

FString UMapIcon::GetBeaconDescShort() {
    return TEXT("");
}

void UMapIcon::ExcludeIconFromStackedFade(bool pExcludeFromStackedFade) {
}

UMapIcon::UMapIcon() {
    this->BeaconInfo = NULL;
    this->NameWidget = NULL;
    this->FilterRegion = NULL;
    this->FilterRegionTexture = NULL;
    this->Texture = NULL;
    this->IconType = EMapToolTipTypes::MAP_TOOL_TIP_TYPE_UNSET;
    this->IconInstance = CreateDefaultSubobject<UMapIconInstance>(TEXT("MapIcon"));
    this->IconInstanceBadge = CreateDefaultSubobject<UMapIconInstance>(TEXT("MapIconBadge"));
}

