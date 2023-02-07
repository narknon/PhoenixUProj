#include "CameraStackStatics.h"
#include "Templates/SubclassOf.h"

class AActor;
class ACameraStackActor;
class ACameraStackManager;
class UCameraStackSettings;
class UObject;

ACameraStackActor* UCameraStackStatics::SpawnCameraStackActorForTarget(AActor* InTargetActor, UCameraStackSettings* InStackSettings, TSubclassOf<ACameraStackActor> InCameraActorClass) {
    return NULL;
}

void UCameraStackStatics::SetPlayerCameraNamedTargetActor(const UObject* WorldContextObject, FName InTargetName, AActor* InTargetActor, int32 PlayerIndex) {
}

void UCameraStackStatics::SetPlayerCameraContext(const UObject* WorldContextObject, FName InContextName, bool bSet, int32 PlayerIndex) {
}

void UCameraStackStatics::ResetPlayerCameraRotation(const UObject* WorldContextObject, int32 PlayerIndex, float ResetDuration, const FRotator& DesiredDelta, bool bResetYaw, bool bResetPitch) {
}

FTransform UCameraStackStatics::GetPlayerViewTransform(const UObject* WorldContextObject, int32 PlayerIndex) {
    return FTransform{};
}

FTransform UCameraStackStatics::GetPlayerCameraTransform(const UObject* WorldContextObject, int32 PlayerIndex) {
    return FTransform{};
}

ACameraStackManager* UCameraStackStatics::GetPlayerCameraStackManager(const UObject* WorldContextObject, int32 PlayerIndex) {
    return NULL;
}

FRotator UCameraStackStatics::GetPlayerCameraArmRotation(const UObject* WorldContextObject, int32 PlayerIndex) {
    return FRotator{};
}

ACameraStackActor* UCameraStackStatics::GetCameraStackActorForTarget(AActor* InTargetActor) {
    return NULL;
}

void UCameraStackStatics::ForceSetPlayerCameraArmRotationTowardsLocation(const UObject* WorldContextObject, int32 PlayerIndex, FVector InTargetLocation) {
}

void UCameraStackStatics::ForceSetPlayerCameraArmRotation(const UObject* WorldContextObject, int32 PlayerIndex, FRotator InRotation) {
}

void UCameraStackStatics::ForcePlayerCameraReset(const UObject* WorldContextObject, int32 PlayerIndex) {
}

void UCameraStackStatics::FilterCurrentPlayerCameraInput(const UObject* WorldContextObject, int32 PlayerIndex, float InDuration) {
}

void UCameraStackStatics::ClearPlayerCameraContext(const UObject* WorldContextObject, FName InContextName, int32 PlayerIndex) {
}

bool UCameraStackStatics::CheckForCameraCutOnTeleport(AActor* InTeleportingActor) {
    return false;
}

UCameraStackStatics::UCameraStackStatics() {
}

