#include "CaptureDeviceItemTool.h"

class AActor;
class USkinnedMeshComponent;

void ACaptureDeviceItemTool::PlayCaptureStinger() const {
}

void ACaptureDeviceItemTool::OnConfirmCapture() {
}



void ACaptureDeviceItemTool::OnCancelCapture() {
}

bool ACaptureDeviceItemTool::IsTargetConsideredLarge() const {
    return false;
}

void ACaptureDeviceItemTool::InvalidateCachedMeshBounds(USkinnedMeshComponent* InMeshComponent) {
}

int32 ACaptureDeviceItemTool::GetTotalNumGates() const {
    return 0;
}

AActor* ACaptureDeviceItemTool::GetTargetActor() const {
    return NULL;
}

float ACaptureDeviceItemTool::GetProgressTowardNextGate() const {
    return 0.0f;
}

int32 ACaptureDeviceItemTool::GetNumGatesPassed() const {
    return 0;
}

float ACaptureDeviceItemTool::GetMaxCapturingDistance() {
    return 0.0f;
}

bool ACaptureDeviceItemTool::GetIsGateActive() const {
    return false;
}

float ACaptureDeviceItemTool::GetCapturingProgress() const {
    return 0.0f;
}

void ACaptureDeviceItemTool::FinishSucceeding() {
}

void ACaptureDeviceItemTool::FinishCancelling() {
}

void ACaptureDeviceItemTool::BeginCapturing() {
}

ACaptureDeviceItemTool::ACaptureDeviceItemTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->WidgetClass = NULL;
    this->PerceptionNoiseEventLoudness = 1.00f;
    this->PerceptionNoiseEventMaxRange = 0.00f;
    this->TriggersSight = false;
    this->TriggersHearing = true;
    this->UsingToolSpeedMode = ETargetSpeedMode::IsSlowWalking;
    this->GracePeriodTime = 10.00f;
    this->BeastCapture_MusicStartEvent = NULL;
    this->BeastCapture_MusicStopEvent = NULL;
    this->BeastCapture_SuccessStingerEvent = NULL;
    this->CurrentCaptureState = ECaptureState::None;
    this->BipedPlayer = NULL;
    this->CurrentDistance = 0.00f;
    this->CaptureWidget = NULL;
    this->bEnableIntermediateGates = true;
}

