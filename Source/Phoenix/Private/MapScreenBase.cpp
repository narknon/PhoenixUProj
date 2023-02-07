#include "MapScreenBase.h"

class UMapBase;
class UMapSubSystem;
class UUIManager;







void UMapScreenBase::UnregisterBButton() {
}





void UMapScreenBase::ShowFastTravelList() {
}

void UMapScreenBase::SetZoomType(EMapZoomTypes::Type ZoomType) {
}



void UMapScreenBase::SetMouseDelta(FVector2D Delta) {
}

void UMapScreenBase::SetMapType(EMapTypes::Type MapType) {
}



void UMapScreenBase::SetLegendStrings(TArray<FLegendItemData>& LegendStrings) {
}


void UMapScreenBase::SetIsFilterShowing(bool ShowFilter) {
}

void UMapScreenBase::SetIconContainerSize() {
}



void UMapScreenBase::SetCoverVisibility(bool Enable) {
}

void UMapScreenBase::SetCoverAlpha(float Alpha) {
}

bool UMapScreenBase::ScreenHandleInput(FKey Input) {
    return false;
}

void UMapScreenBase::RightMouseButtonReleased() {
}

void UMapScreenBase::RightMouseButtonPressed() {
}

void UMapScreenBase::RegisterBButton() {
}








bool UMapScreenBase::MouseTimeGreaterThanClick(TEnumAsByte<EMapScreenMouseButtonID> buttonID) {
    return false;
}

void UMapScreenBase::MiddleMouseButtonReleased() {
}

void UMapScreenBase::MiddleMouseButtonPressed() {
}





void UMapScreenBase::LockMapInput(bool Lock) {
}

void UMapScreenBase::LeftMouseButtonReleased() {
}

void UMapScreenBase::LeftMouseButtonPressed() {
}

bool UMapScreenBase::IsMouseButtonAClick(TEnumAsByte<EMapScreenMouseButtonID> buttonID) {
    return false;
}

bool UMapScreenBase::IsFastTravelListVisible() {
    return false;
}

bool UMapScreenBase::IsAnyTutorialActive() const {
    return false;
}




void UMapScreenBase::HideFastTravelList() {
}

float UMapScreenBase::GetZoomInputDelta() {
    return 0.0f;
}

float UMapScreenBase::GetZoomFactor() {
    return 0.0f;
}

UUIManager* UMapScreenBase::GetUIManager() {
    return NULL;
}

TEnumAsByte<EMapZoomTypes::Type> UMapScreenBase::GetTier() {
    return EMapZoomTypes::MAP_TOOL_TIP_TYPE_INVALID;
}

float UMapScreenBase::GetPressedButtonTime(TEnumAsByte<EMapScreenMouseButtonID> buttonID) {
    return 0.0f;
}

FVector2D UMapScreenBase::GetMovementDelta() {
    return FVector2D{};
}

FVector2D UMapScreenBase::GetMouseDelta() {
    return FVector2D{};
}

FMapScreenMouseButton UMapScreenBase::GetMouseButtonInput(TEnumAsByte<EMapScreenMouseButtonID> buttonID) {
    return FMapScreenMouseButton{};
}

TEnumAsByte<EMapTypes::Type> UMapScreenBase::GetMapType() {
    return EMapTypes::MAP_TYPE_NONE;
}

UMapSubSystem* UMapScreenBase::GetMapSubSystem() {
    return NULL;
}

UMapBase* UMapScreenBase::GetMapBase() {
    return NULL;
}

bool UMapScreenBase::GetIsMouseInScreen() {
    return false;
}

bool UMapScreenBase::GetIsFilterShowing() {
    return false;
}

FUMGConsolidatedAxisInputData UMapScreenBase::GetInputAxisData() {
    return FUMGConsolidatedAxisInputData{};
}





void UMapScreenBase::ClearMouseButtons() {
}

void UMapScreenBase::ClearMouseButton(EMapScreenMouseButtonID buttonID) {
}

UMapScreenBase::UMapScreenBase() {
    this->ToolTipPopup2 = NULL;
    this->RegionInfoPopup = NULL;
    this->DebugRegion = NULL;
    this->MapPawn = NULL;
    this->FastTravelList = NULL;
    this->IconContainer = NULL;
}

