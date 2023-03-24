#include "CameraStackManager.h"
#include "CameraStackActor.h"
#include "Templates/SubclassOf.h"

class AActor;
class UCameraStackSettings;

void ACameraStackManager::SwitchToCamera(AActor* NewCamera, bool bInOverrideBlendDuration, float InBlendDuration) {
}

void ACameraStackManager::SwitchToActorsCameraActor(const AActor* newActor, bool bInOverrideBlendDuration, float InBlendDuration) {
}

void ACameraStackManager::SwitchToActiveTargetCamera(bool bInOverrideBlendDuration, float InBlendDuration) {
}

ACameraStackActor* ACameraStackManager::SpawnCameraActorForTarget(AActor* InTargetActor, UCameraStackSettings* InStackSettings, TSubclassOf<ACameraStackActor> InCameraActorClass) {
    return NULL;
}

void ACameraStackManager::SetFixedCameraInPlace(bool bSetToFixed) {
}

void ACameraStackManager::RemoveFromCameraActorMap(AActor* InActor) {
}

bool ACameraStackManager::IsCameraFixedInPlace() const {
    return false;
}

FName ACameraStackManager::GetCameraStyle() const {
    return NAME_None;
}

ACameraStackActor* ACameraStackManager::GetActorsCameraActor(const AActor* InActor) const {
    return NULL;
}

ACameraStackManager::ACameraStackManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DefaultCameraStyle = TEXT("Sony");
    this->DefaultActorClass = ACameraStackActor::StaticClass();
    this->PostProcessHandler = NULL;
    this->bOnlyTickAssigned = false;
    this->bOverrideBlendDuration = false;
    this->BlendDurationOverride = 0.00f;
    this->AspectRatioWidget = NULL;
    this->RuleOfThirdsWidget = NULL;
    this->FocusPlaneVisualizationMesh = NULL;
    this->FocusPlaneVisualizationMaterial = NULL;
    this->DebugFocusPlaneComponent = NULL;
    this->DebugFocusPlaneMID = NULL;
}

