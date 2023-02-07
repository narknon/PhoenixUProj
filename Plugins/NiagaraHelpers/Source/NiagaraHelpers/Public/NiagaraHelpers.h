#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ENiagaraHelpersPrimMatchMode.h"
#include "ENiagaraHelpersPrimRule.h"
#include "ENiagaraSpawnBoundsMethod.h"
#include "NiagaraHelpersPrimFilter.h"
#include "NiagaraSystemSpawnAttachedInfo.h"
#include "NiagaraSystemSpawnAttachedPointInfo.h"
#include "NiagaraSystemSpawnInfo.h"
#include "NiagaraSystemSpawnMultiSkeletalInfo.h"
#include "NiagaraSystemSpawnMultiStaticInfo.h"
#include "NiagaraHelpers.generated.h"

class AActor;
class UNiagaraComponent;
class UNiagaraParameterCollectionInstance;
class UNiagaraSystem;
class UObject;
class UPrimitiveComponent;
class USceneComponent;
class USkinnedMeshComponent;

UCLASS(Blueprintable)
class NIAGARAHELPERS_API UNiagaraHelpers : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UNiagaraHelpers();
    UFUNCTION(BlueprintCallable)
    static void SpawnSystemOnStaticMeshes(AActor* Actor, UNiagaraSystem* NiagaraSystem, FNiagaraSystemSpawnMultiStaticInfo SpawnInfo, FNiagaraHelpersPrimFilter Filter, TArray<UNiagaraComponent*>& NiagaraComponents);
    
    UFUNCTION(BlueprintCallable)
    static void SpawnSystemOnSkeletalMeshes(AActor* Actor, UNiagaraSystem* NiagaraSystem, FNiagaraSystemSpawnMultiSkeletalInfo SpawnInfo, FNiagaraHelpersPrimFilter Filter, TArray<UNiagaraComponent*>& NiagaraComponents);
    
    UFUNCTION(BlueprintCallable)
    static void SpawnSystemOnPrimitives(AActor* Actor, UNiagaraSystem* NiagaraSystem, FNiagaraSystemSpawnAttachedInfo SpawnInfo, FNiagaraHelpersPrimFilter Filter, TArray<UNiagaraComponent*>& NiagaraComponents);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SpawnInWorld(UObject* WorldContextObject, UNiagaraSystem* NiagaraSystem, FNiagaraSystemSpawnInfo SpawnInfo, UNiagaraComponent*& NiagaraComponent);
    
    UFUNCTION(BlueprintCallable)
    static void SpawnAttachedActor(AActor* Actor, UNiagaraSystem* NiagaraSystem, FNiagaraSystemSpawnAttachedPointInfo SpawnInfo, UNiagaraComponent*& NiagaraComponent);
    
    UFUNCTION(BlueprintCallable)
    static void SpawnAttached(USceneComponent* SceneComponent, UNiagaraSystem* NiagaraSystem, FNiagaraSystemSpawnAttachedPointInfo SpawnInfo, UNiagaraComponent*& NiagaraComponent);
    
    UFUNCTION(BlueprintCallable)
    static void NPCSetParameterVector(UNiagaraParameterCollectionInstance* npci, const FString& ParamName, FVector Value);
    
    UFUNCTION(BlueprintCallable)
    static void NPCSetParameterFloat(UNiagaraParameterCollectionInstance* npci, const FString& ParamName, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void NPCSetParameterColor(UNiagaraParameterCollectionInstance* npci, const FString& ParamName, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FNiagaraHelpersPrimFilter MakePrimFilterPrimitives(ENiagaraHelpersPrimRule Rule, TArray<UPrimitiveComponent*> Primitives, ENiagaraHelpersPrimMatchMode MatchMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FNiagaraHelpersPrimFilter MakePrimFilterPrimitive(ENiagaraHelpersPrimRule Rule, UPrimitiveComponent* Primitive, ENiagaraHelpersPrimMatchMode MatchMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FNiagaraHelpersPrimFilter MakePrimFilterNames(ENiagaraHelpersPrimRule Rule, TArray<FName> Primitives, ENiagaraHelpersPrimMatchMode MatchMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FNiagaraHelpersPrimFilter MakePrimFilterName(ENiagaraHelpersPrimRule Rule, FName Primitive, ENiagaraHelpersPrimMatchMode MatchMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetEmitterNames(UNiagaraSystem* NiagaraSystem, TArray<FName>& emitterNames, bool includeHidden);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ComputeComponentBoundsMeasure(TArray<USceneComponent*> Components, ENiagaraSpawnBoundsMethod Method, float& Measure, float LinearPower);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ComputeActorStaticMeshBoundsMeasure(AActor* Actor, ENiagaraSpawnBoundsMethod Method, float& Measure, float LinearPower);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ComputeActorSkeletalMeshBoundsMeasure(AActor* Actor, ENiagaraSpawnBoundsMethod Method, float& Measure, float LinearPower);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ComputeActorPrimitiveBoundsMeasure(AActor* Actor, ENiagaraSpawnBoundsMethod Method, float& Measure, float LinearPower);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ComputeActorMeshBoundsMeasure(AActor* Actor, ENiagaraSpawnBoundsMethod Method, float& Measure, float LinearPower);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ActorFindSocketOnComponent(AActor* Actor, FName SocketName, USceneComponent*& ComponentWithSocket, bool bDeepSearchComponents);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ActorFindBoneOrSocketOnComponent(AActor* Actor, FName BoneOrSocketName, USceneComponent*& ComponentWithBoneOrSocket, int32& BoneIndex, bool bDeepSearchComponents);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ActorFindBoneOnComponent(AActor* Actor, FName BoneName, USkinnedMeshComponent*& ComponentWithBone, int32& BoneIndex, bool bDeepSearchComponents);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ActorBestDefaultAttachComponent(AActor* Actor, USceneComponent*& AttachComponent);
    
};

