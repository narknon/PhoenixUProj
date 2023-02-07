#include "MapBase.h"

class APlayerController;
class UBeaconInfo;
class UMapIcon;
class UMapScreenBase;
class UObject;
class UPopupScreen;
class UTexture2D;
class UWorldSupportWorld;

bool UMapBase::TutorialDisablesMapBehavior_Blueprint(TEnumAsByte<EMapLocTypes::Type> MapBehavior) {
    return false;
}

void UMapBase::TrackHoveredMission() {
}

void UMapBase::SetTurnOffFogCheck(bool pTurnOffFogCheck) {
}

void UMapBase::SetLastHoveredIcon(UMapIcon* lastIcon) {
}

void UMapBase::SetKnowledgeCardActive(bool pKnowledgeCardActive) {
}

void UMapBase::SetHoveredIcon(UMapIcon* NewHoverIcon) {
}

void UMapBase::SetCoverDisplayed(bool Enable) {
}

void UMapBase::SetCoverAlpha(float Alpha) {
}

void UMapBase::ReturnCursorToPlayerLocation() {
}

void UMapBase::PlaceWayMarkerClick() {
}

void UMapBase::PlaceWayMarkerBP() {
}

void UMapBase::OnWaitPopupDismissed(UPopupScreen* Popup, int32 ConfirmationResult) {
}

void UMapBase::OnMenuClosedStartFastTravel() {
}

float UMapBase::IsWaitAvailable() {
    return 0.0f;
}

bool UMapBase::IsMissionByBeacon(UBeaconInfo* BeaconInfo) {
    return false;
}

bool UMapBase::IsMissionBeaconNoArea(EBeaconType BeaconType) {
    return false;
}

bool UMapBase::IsMissionBeacon(EBeaconType BeaconType) {
    return false;
}

void UMapBase::InputReadyCallback() {
}

void UMapBase::IconOutlineTextureCallback(UTexture2D* Texture, UObject* Param) {
}

void UMapBase::IconInstanceTextureCallback(UTexture2D* Texture, UObject* Param) {
}

void UMapBase::GoToPreviousMap() {
}

void UMapBase::GoToNextMap() {
}

TEnumAsByte<EMapZoomTypes::Type> UMapBase::GetZoomTypeBP() {
    return EMapZoomTypes::MAP_TOOL_TIP_TYPE_INVALID;
}

float UMapBase::GetZoomFactor() {
    return 0.0f;
}

FName UMapBase::GetWorldName() {
    return NAME_None;
}

bool UMapBase::GetTurnOffFogCheck() {
    return false;
}

UWorldSupportWorld* UMapBase::GetMapWorld() {
    return NULL;
}

UMapScreenBase* UMapBase::GetMapWidget() {
    return NULL;
}

bool UMapBase::GetMapVisible() {
    return false;
}

TEnumAsByte<EMapTypes::Type> UMapBase::GetMapType() {
    return EMapTypes::MAP_TYPE_NONE;
}

float UMapBase::GetMapScale() {
    return 0.0f;
}

bool UMapBase::GetMapReadyCalled() {
    return false;
}

APlayerController* UMapBase::GetMapPlayerController() {
    return NULL;
}

FName UMapBase::GetMapName() {
    return NAME_None;
}

TEnumAsByte<EMapFadeState> UMapBase::GetMapFadeState() {
    return MAP_FADE_STATE_IDLE;
}

UMapIcon* UMapBase::GetLastHoveredIcon() {
    return NULL;
}

bool UMapBase::GetKnowledgeCardActive() {
    return false;
}

bool UMapBase::GetIsMouseDragging() {
    return false;
}

bool UMapBase::GetHoveredState() {
    return false;
}

UMapIcon* UMapBase::GetHoveredIcon() {
    return NULL;
}

bool UMapBase::GetCameraLerpInProgress() {
    return false;
}

bool UMapBase::CanGoToMissionLogFromIcon(const UMapIcon* MapIcon) const {
    return false;
}

void UMapBase::AdvanceTime() {
}

UMapBase::UMapBase() {
    this->HogwartsDotIconScale = 0.40f;
    this->ClosestFastTravelFX = NULL;
    this->ClosestFastTravelIcon = NULL;
    this->MapIconWidgetClass = NULL;
    this->BaseMapWidget = NULL;
    this->MapBPWidgetClass = NULL;
    this->MapIconBPClass = NULL;
    this->MapSpriteIconBPClass = NULL;
    this->MapWorld = NULL;
    this->PlayerMarkerIcon = NULL;
    this->PlayerMarkerMaterial = NULL;
    this->DebugTextPanel = NULL;
    this->WayMarkerScale = 1.00f;
    this->hoverIcon = NULL;
    this->LastHoverIcon = NULL;
    this->LastHoverIconUnhover = NULL;
    this->MovementComponent = NULL;
    this->MapPawn = NULL;
    this->ZoomFadeStart = 0.30f;
    this->ZoomFadeEnd = 0.70f;
    this->MinimumAlpha = 0.50f;
    this->MaxFrameCountToCover = 2;
    this->MapAnalogControllerMin = 0.25f;
    this->CursorSnapDistance = 40.00f;
    this->CameraParameters = NULL;
    this->DebugCameraParameters = NULL;
}

