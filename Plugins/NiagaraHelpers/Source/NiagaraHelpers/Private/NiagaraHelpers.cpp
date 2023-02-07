#include "NiagaraHelpers.h"

class AActor;
class UNiagaraComponent;
class UNiagaraParameterCollectionInstance;
class UNiagaraSystem;
class UObject;
class UPrimitiveComponent;
class USceneComponent;
class USkinnedMeshComponent;

void UNiagaraHelpers::SpawnSystemOnStaticMeshes(AActor* Actor, UNiagaraSystem* NiagaraSystem, FNiagaraSystemSpawnMultiStaticInfo SpawnInfo, FNiagaraHelpersPrimFilter Filter, TArray<UNiagaraComponent*>& NiagaraComponents) {
}

void UNiagaraHelpers::SpawnSystemOnSkeletalMeshes(AActor* Actor, UNiagaraSystem* NiagaraSystem, FNiagaraSystemSpawnMultiSkeletalInfo SpawnInfo, FNiagaraHelpersPrimFilter Filter, TArray<UNiagaraComponent*>& NiagaraComponents) {
}

void UNiagaraHelpers::SpawnSystemOnPrimitives(AActor* Actor, UNiagaraSystem* NiagaraSystem, FNiagaraSystemSpawnAttachedInfo SpawnInfo, FNiagaraHelpersPrimFilter Filter, TArray<UNiagaraComponent*>& NiagaraComponents) {
}

void UNiagaraHelpers::SpawnInWorld(UObject* WorldContextObject, UNiagaraSystem* NiagaraSystem, FNiagaraSystemSpawnInfo SpawnInfo, UNiagaraComponent*& NiagaraComponent) {
}

void UNiagaraHelpers::SpawnAttachedActor(AActor* Actor, UNiagaraSystem* NiagaraSystem, FNiagaraSystemSpawnAttachedPointInfo SpawnInfo, UNiagaraComponent*& NiagaraComponent) {
}

void UNiagaraHelpers::SpawnAttached(USceneComponent* SceneComponent, UNiagaraSystem* NiagaraSystem, FNiagaraSystemSpawnAttachedPointInfo SpawnInfo, UNiagaraComponent*& NiagaraComponent) {
}

void UNiagaraHelpers::NPCSetParameterVector(UNiagaraParameterCollectionInstance* npci, const FString& ParamName, FVector Value) {
}

void UNiagaraHelpers::NPCSetParameterFloat(UNiagaraParameterCollectionInstance* npci, const FString& ParamName, float Value) {
}

void UNiagaraHelpers::NPCSetParameterColor(UNiagaraParameterCollectionInstance* npci, const FString& ParamName, FLinearColor Value) {
}

FNiagaraHelpersPrimFilter UNiagaraHelpers::MakePrimFilterPrimitives(ENiagaraHelpersPrimRule Rule, TArray<UPrimitiveComponent*> Primitives, ENiagaraHelpersPrimMatchMode MatchMode) {
    return FNiagaraHelpersPrimFilter{};
}

FNiagaraHelpersPrimFilter UNiagaraHelpers::MakePrimFilterPrimitive(ENiagaraHelpersPrimRule Rule, UPrimitiveComponent* Primitive, ENiagaraHelpersPrimMatchMode MatchMode) {
    return FNiagaraHelpersPrimFilter{};
}

FNiagaraHelpersPrimFilter UNiagaraHelpers::MakePrimFilterNames(ENiagaraHelpersPrimRule Rule, TArray<FName> Primitives, ENiagaraHelpersPrimMatchMode MatchMode) {
    return FNiagaraHelpersPrimFilter{};
}

FNiagaraHelpersPrimFilter UNiagaraHelpers::MakePrimFilterName(ENiagaraHelpersPrimRule Rule, FName Primitive, ENiagaraHelpersPrimMatchMode MatchMode) {
    return FNiagaraHelpersPrimFilter{};
}

void UNiagaraHelpers::GetEmitterNames(UNiagaraSystem* NiagaraSystem, TArray<FName>& emitterNames, bool includeHidden) {
}

void UNiagaraHelpers::ComputeComponentBoundsMeasure(TArray<USceneComponent*> Components, ENiagaraSpawnBoundsMethod Method, float& Measure, float LinearPower) {
}

void UNiagaraHelpers::ComputeActorStaticMeshBoundsMeasure(AActor* Actor, ENiagaraSpawnBoundsMethod Method, float& Measure, float LinearPower) {
}

void UNiagaraHelpers::ComputeActorSkeletalMeshBoundsMeasure(AActor* Actor, ENiagaraSpawnBoundsMethod Method, float& Measure, float LinearPower) {
}

void UNiagaraHelpers::ComputeActorPrimitiveBoundsMeasure(AActor* Actor, ENiagaraSpawnBoundsMethod Method, float& Measure, float LinearPower) {
}

void UNiagaraHelpers::ComputeActorMeshBoundsMeasure(AActor* Actor, ENiagaraSpawnBoundsMethod Method, float& Measure, float LinearPower) {
}

void UNiagaraHelpers::ActorFindSocketOnComponent(AActor* Actor, FName SocketName, USceneComponent*& ComponentWithSocket, bool bDeepSearchComponents) {
}

void UNiagaraHelpers::ActorFindBoneOrSocketOnComponent(AActor* Actor, FName BoneOrSocketName, USceneComponent*& ComponentWithBoneOrSocket, int32& BoneIndex, bool bDeepSearchComponents) {
}

void UNiagaraHelpers::ActorFindBoneOnComponent(AActor* Actor, FName BoneName, USkinnedMeshComponent*& ComponentWithBone, int32& BoneIndex, bool bDeepSearchComponents) {
}

void UNiagaraHelpers::ActorBestDefaultAttachComponent(AActor* Actor, USceneComponent*& AttachComponent) {
}

UNiagaraHelpers::UNiagaraHelpers() {
}

