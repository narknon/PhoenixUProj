#include "ObjectFadeMaster.h"

class AActor;
class UMeshComponent;

bool AObjectFadeMaster::MeshStartFadeEaseFunction(UMeshComponent* Mesh, const FObjectFadeParamsEaseFunction& Setup, EObjectFadeCompletedAction FadeCompletedAction, float TimeFactorOverride) {
    return false;
}

bool AObjectFadeMaster::MeshStartFadeDirectCurve(UMeshComponent* Mesh, const FObjectFadeParamsCurve& Setup, EObjectFadeCompletedAction FadeCompletedAction, float TimeFactorOverride) {
    return false;
}

bool AObjectFadeMaster::MeshStartFade(UMeshComponent* Mesh, const FObjectFadeParamsSpeedDuration& Setup, EObjectFadeCompletedAction FadeCompletedAction, float TimeFactorOverride) {
    return false;
}

void AObjectFadeMaster::MeshRemoveFade(UMeshComponent* Mesh, bool& wasFading) {
}

void AObjectFadeMaster::MeshIsFadingOut(UMeshComponent* Mesh, bool& isFading, bool& isDone) {
}

void AObjectFadeMaster::MeshIsFadingIn(UMeshComponent* Mesh, bool& isFading, bool& isDone) {
}

bool AObjectFadeMaster::ActorStartFadeEaseFunction(AActor* Actor, const FObjectFadeParamsEaseFunction& Setup, EObjectFadeCompletedAction FadeCompletedAction, float TimeFactorOverride) {
    return false;
}

bool AObjectFadeMaster::ActorStartFadeDirectCurve(AActor* Actor, const FObjectFadeParamsCurve& Setup, EObjectFadeCompletedAction FadeCompletedAction, float TimeFactorOverride) {
    return false;
}

bool AObjectFadeMaster::ActorStartFade(AActor* Actor, const FObjectFadeParamsSpeedDuration& Setup, EObjectFadeCompletedAction FadeCompletedAction, float TimeFactorOverride) {
    return false;
}

void AObjectFadeMaster::ActorSetFadeInOut(AActor* Actor, EObjectFadeDirection Direction, EObjectFadeMasterState& FadeState, float Duration, EObjectFadeCompletedAction FadeInCompletedAction, EObjectFadeCompletedAction FadeOutCompletedAction, bool bFadeInIfNotInSystem) {
}

void AObjectFadeMaster::ActorRemoveFade(AActor* Actor, bool& wasFading) {
}

void AObjectFadeMaster::ActorPingPongFade(AActor* Actor, EObjectFadeDirection Direction, EObjectFadeMasterState& FadeState, float Duration) {
}

void AObjectFadeMaster::ActorIsFadingOut(AActor* Actor, bool& isFading, bool& isDone) {
}

void AObjectFadeMaster::ActorIsFadingIn(AActor* Actor, bool& isFading, bool& isDone) {
}

AObjectFadeMaster::AObjectFadeMaster() {
}

