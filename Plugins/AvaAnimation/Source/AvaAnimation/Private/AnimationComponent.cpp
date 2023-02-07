#include "AnimationComponent.h"
#include "Templates/SubclassOf.h"

class UAnimLayersAsset;
class UIKDriver;
class UObject;

void UAnimationComponent::StartSettingPoseFixupEnabled(const bool bInEnabled, const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration) {
}

void UAnimationComponent::StartSettingLookAtEnabled(const bool bInEnabled, const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration) {
}

void UAnimationComponent::StartSettingIKEnabled(const bool bInEnabled, const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration) {
}

void UAnimationComponent::StartSettingFloorContactEnabled(const bool bInEnabled, const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration) {
}

void UAnimationComponent::StartIKBlendOut(float Duration) {
}

void UAnimationComponent::StartIKBlendIn(float Duration) {
}

void UAnimationComponent::SetPlayerIKEnabled(bool State) {
}

void UAnimationComponent::SetLadderInfo(float BottomRungZ, float TopRungZ, float RungSpacing, FVector LadderWorldPos, FVector LadderFaceNormal) {
}

void UAnimationComponent::SetLadderIKEnabled(bool Enabled) {
}

void UAnimationComponent::SetGlobalIKEnabled(bool State) {
}

void UAnimationComponent::SetDirectionWeight(EAnimationDirections Direction, EAnimationDirectionSource Source, float weight) {
}

void UAnimationComponent::SetDirectionTargetAndWeightNoCap(EAnimationDirections Direction, EAnimationDirectionSource Source, FVector TargetInWorldSpace, float weight) {
}

void UAnimationComponent::SetDirectionTargetAndWeight(EAnimationDirections Direction, EAnimationDirectionSource Source, FVector TargetInWorldSpace, float weight) {
}

void UAnimationComponent::SetAnimLayersAsset(UAnimLayersAsset* InLayersAsset) {
}

void UAnimationComponent::ResetDefaultDirectionNow(EAnimationDirections Direction) {
}

bool UAnimationComponent::IsPlayerIKEnabled() {
    return false;
}

bool UAnimationComponent::IsGlobalIKEnabled() {
    return false;
}

UIKDriver* UAnimationComponent::GetIKDriverFromClass(TSubclassOf<UIKDriver> IKDriverClass) const {
    return NULL;
}

float UAnimationComponent::GetIKBlendWeight() const {
    return 0.0f;
}

bool UAnimationComponent::GetDirectionTargetAndWeight(EAnimationDirections Direction, FVector& OutTargetInWorldSpace, float& OutWeight) const {
    return false;
}

bool UAnimationComponent::GetDefaultDirection(EAnimationDirections Direction, FVector& OutDefaultDirectionInComponentSpace) const {
    return false;
}

void UAnimationComponent::FinishSettingPoseFixupEnabled(const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration) {
}

void UAnimationComponent::FinishSettingLookAtEnabled(const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration) {
}

void UAnimationComponent::FinishSettingIKEnabled(const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration) {
}

void UAnimationComponent::FinishSettingFloorContactEnabled(const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration) {
}

UAnimationComponent::UAnimationComponent() {
    this->LayersAsset = NULL;
    this->ControlRigClass = NULL;
    this->ControlRig = NULL;
    this->LadderContactEnabled = false;
    this->HighestLODLevelForIK = 3;
    this->LOD_IKBlendOutDuration = 2.00f;
    this->LOD_IKBlendInDuration = 1.00f;
    this->StrideWarpFactor = 1.00f;
    this->FootPlant = EFootPlantEnum::FOOTPLANT_UNAVAILABLE;
    this->bHoldFootPositionWhenPlanted = false;
    this->CapsuleInterpSpeed = 0.00f;
    this->ResetDefaultDirection.AddDefaulted(5);
    this->MaxLookAlpha = 1.00f;
    this->TimeDelayProvider = NULL;
    this->BlendInTimeProvider = NULL;
    this->LastSequence = NULL;
    this->LastSequenceTime = 0.00f;
    this->TickAssetPlayerProxy = NULL;
}

