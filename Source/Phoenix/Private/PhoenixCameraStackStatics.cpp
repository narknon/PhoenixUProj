#include "PhoenixCameraStackStatics.h"
#include "Templates/SubclassOf.h"

class AActor;
class ACameraStackLookAtTargetActor;
class UCameraShakeBase;
class UObject;

ACameraStackLookAtTargetActor* UPhoenixCameraStackStatics::SpawnCameraLookAtTargetActor(const UObject* WorldContextObject, FVector WorldLocation, ECameraStackLookAtStrength LookAtStrength) {
    return NULL;
}

void UPhoenixCameraStackStatics::SetPlayerCameraLookAtLocationForDuration(const UObject* WorldContextObject, FVector LookAtLocation, float Duration, ECameraStackLookAtStrength LookAtStrength, int32 PlayerIndex) {
}

void UPhoenixCameraStackStatics::SetPlayerCameraLookAtLocation(const UObject* WorldContextObject, FVector LookAtLocation, ECameraStackLookAtStrength LookAtStrength, int32 PlayerIndex) {
}

void UPhoenixCameraStackStatics::SetPlayerCameraLookAtActorForDuration(const UObject* WorldContextObject, AActor* LookAtActor, float Duration, ECameraStackLookAtStrength LookAtStrength, int32 PlayerIndex) {
}

void UPhoenixCameraStackStatics::SetPlayerCameraLookAtActor(const UObject* WorldContextObject, AActor* LookAtActor, ECameraStackLookAtStrength LookAtStrength, int32 PlayerIndex) {
}

void UPhoenixCameraStackStatics::ReleasePlayerCameraLookAt(const UObject* WorldContextObject, int32 PlayerIndex) {
}

void UPhoenixCameraStackStatics::PlayWorldCameraShakeScale(const UObject* WorldContextObject, TSubclassOf<UCameraShakeBase> Shake, FVector epicenter, float InnerRadius, float OuterRadius, float Falloff, float InScale, bool bOrientShakeTowardsEpicenter) {
}

ACameraStackLookAtTargetActor* UPhoenixCameraStackStatics::GetLookAtTargetActorWithStrength(const UObject* WorldContextObject, ECameraStackLookAtStrength LookAtStrength, int32 PlayerIndex) {
    return NULL;
}

ACameraStackLookAtTargetActor* UPhoenixCameraStackStatics::GetHighestPriorityLookAtTargetActor(const UObject* WorldContextObject, int32 PlayerIndex) {
    return NULL;
}

UPhoenixCameraStackStatics::UPhoenixCameraStackStatics() {
}

