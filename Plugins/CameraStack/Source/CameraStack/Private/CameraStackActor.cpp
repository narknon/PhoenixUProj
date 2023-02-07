#include "CameraStackActor.h"
#include "CameraStack.h"
#include "CameraStackCineComponent.h"
#include "CameraStackInput.h"
#include "CameraStackTarget.h"
#include "Templates/SubclassOf.h"

class AActor;
class UCameraStackBehavior;
class UCameraStackBehaviorCore;
class UObject;

void ACameraStackActor::SetNamedSecondaryTargetActor(FName InName, AActor* InActor) {
}

void ACameraStackActor::SetCameraContext(FName InContextName, bool bSet) {
}

void ACameraStackActor::ResetRotationToTarget(float InBlendDuration, const FRotator& InDesiredDelta, bool bInResetYaw, bool bInResetPitch) {
}

bool ACameraStackActor::IsCameraContextSet(FName InContextName) const {
    return false;
}

FTransform ACameraStackActor::GetUnblendedCameraViewTransform() const {
    return FTransform{};
}

UCameraStackTarget* ACameraStackActor::GetTarget() const {
    return NULL;
}

AActor* ACameraStackActor::GetNamedSecondaryTargetActor(FName InName) const {
    return NULL;
}

UCameraStackInput* ACameraStackActor::GetInput() const {
    return NULL;
}

FTransform ACameraStackActor::GetCameraViewTransform() const {
    return FTransform{};
}

UCameraStack* ACameraStackActor::GetBehaviors() const {
    return NULL;
}

FRotator ACameraStackActor::GetArmRotation() const {
    return FRotator{};
}

void ACameraStackActor::ForceSetArmRotationTowardsLocation(FVector InLocation) {
}

void ACameraStackActor::ForceSetArmRotation(FRotator InRotation, bool bUseDefaultPitch) {
}

void ACameraStackActor::ForceCameraReset() {
}

UCameraStackBehavior* ACameraStackActor::CreateNonCoreBehavior(TSubclassOf<UCameraStackBehavior> BehaviorClass, UObject* Template) {
    return NULL;
}

UCameraStackBehaviorCore* ACameraStackActor::CreateCoreBehavior(TSubclassOf<UCameraStackBehaviorCore> BehaviorClass, UObject* Template) {
    return NULL;
}

void ACameraStackActor::ClearCameraContext(FName InContextName) {
}

ACameraStackActor::ACameraStackActor() {
    this->CameraComponent = CreateDefaultSubobject<UCameraStackCineComponent>(TEXT("Camera"));
    this->Target = CreateDefaultSubobject<UCameraStackTarget>(TEXT("Target"));
    this->bDestroyIfSpawnedOnEndViewTarget = false;
    this->InputPriorityOverride = -1;
    this->bOverrideInputMappings = false;
    this->bUnbindInputOnEndViewTarget = true;
    this->BehaviorStack = CreateDefaultSubobject<UCameraStack>(TEXT("BehaviorStack"));
    this->Input = CreateDefaultSubobject<UCameraStackInput>(TEXT("Input"));
    this->CameraInputComponent = NULL;
}

