#include "MultiFXManager.h"

class AActor;
class UNiagaraComponent;
class UObject;
class UParticleSystemComponent;
class USceneComponent;
class USkinFXComponent;

void UMultiFXManager::UpdateFX() {
}

void UMultiFXManager::SpawnMultiFXPlus(const FMultiFXPlus& MultiPlus, UObject* Object, FMultiFXPlusHandles& FXHandles, const FVector& Location, const FRotator& Rotation) {
}

FMultiFXHandle UMultiFXManager::SpawnMultiFXAttached(const FMultiFX& MultiFX, USceneComponent* AttachToComponent, const FMaterialSwapParameters& MaterialSwapParameters, FName AttachPointName, const FVector& Location, const FRotator& Rotation, const FVector& Scale, TEnumAsByte<EAttachLocation::Type> LocationType, bool bAutoDestroy) {
    return FMultiFXHandle{};
}

FMultiFXHandle UMultiFXManager::SpawnMultiFXAtLocation(const FMultiFX& MultiFX, UObject* WorldContextObject, const FMaterialSwapParameters& MaterialSwapParameters, const FVector& Location, const FRotator& Rotation, const FVector& Scale, bool bAutoDestroy) {
    return FMultiFXHandle{};
}

void UMultiFXManager::SetVfxRotation(const FMultiFXHandle& InHandle, const FRotator& Rotation) {
}

void UMultiFXManager::SetVfxLocation(const FMultiFXHandle& InHandle, const FVector& Location) {
}

void UMultiFXManager::SetCustomTimeDilation(const FMultiFXHandle& InHandle, float Dilation) {
}

void UMultiFXManager::MovementStopped(AActor* InActor) {
}

bool UMultiFXManager::IsVfxPlaying(const FMultiFXHandle& InHandle) {
    return false;
}

bool UMultiFXManager::IsVfxLooping(const FMultiFXHandle& InHandle) {
    return false;
}

bool UMultiFXManager::IsValid(const FMultiFXHandle& InHandle) {
    return false;
}

bool UMultiFXManager::IsPlusComplete(const FMultiFXPlusHandles& InHandles) {
    return false;
}

FRotator UMultiFXManager::GetVfxRotation(const FMultiFXHandle& InHandle) {
    return FRotator{};
}

FVector UMultiFXManager::GetVfxLocation(const FMultiFXHandle& InHandle) {
    return FVector{};
}

USkinFXComponent* UMultiFXManager::GetSkinFxComponent(const FMultiFXHandle& InHandle) {
    return NULL;
}

int32 UMultiFXManager::GetSfxHandle(const FMultiFXHandle& InHandle) {
    return 0;
}

UParticleSystemComponent* UMultiFXManager::GetParticleSystemComponent(const FMultiFXHandle& InHandle) {
    return NULL;
}

UNiagaraComponent* UMultiFXManager::GetNiagaraComponent(const FMultiFXHandle& InHandle) {
    return NULL;
}

float UMultiFXManager::GetCustomTimeDilation(const FMultiFXHandle& InHandle) {
    return 0.0f;
}

void UMultiFXManager::DetachVfxRule(const FMultiFXHandle& InHandle, EDetachmentRule DetachmentRules) {
}

void UMultiFXManager::DestroyPlus(FMultiFXPlusHandles& InHandles, bool bImmediate, ESkinFXEffectEndStyle EndStyle) {
}

void UMultiFXManager::Destroy(FMultiFXHandle& InHandle, bool bImmediate, ESkinFXEffectEndStyle EndStyle) {
}

UMultiFXManager::UMultiFXManager() {
}

