#include "HoverDroneController.h"

class APhoenixHoverDronePawn;

void AHoverDroneController::ToggleHUD() {
}

void AHoverDroneController::StartHoverDroneFromSystemMenu() {
}

void AHoverDroneController::SetPlayerBounds(FVector BoundsMin, FVector BoundsMax) {
}

void AHoverDroneController::GetPlayerBounds(FVector& Max, FVector& Min) const {
}

float AHoverDroneController::GetPawnAltitude() const {
    return 0.0f;
}

APhoenixHoverDronePawn* AHoverDroneController::GetDronePawn() {
    return NULL;
}

FString AHoverDroneController::GetControlModeString() const {
    return TEXT("");
}

TEnumAsByte<EHoverDroneControlMode::Type> AHoverDroneController::GetControlMode() const {
    return EHoverDroneControlMode::Player;
}

AHoverDroneController::AHoverDroneController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ControlModePawnClass[0] = NULL;
    this->ControlModePawnClass[1] = NULL;
    this->ControlModePawnClass[2] = NULL;
    this->m_MinimapWidgetClass = NULL;
    this->m_pFollowActor = NULL;
    this->m_pInputComponent = NULL;
    this->m_pPlayerController = NULL;
    this->JumpToBookmarkCameraFadeTime = 0.50f;
    this->JumpToBookmarkCameraHoldBlackTime = 1.50f;
}

