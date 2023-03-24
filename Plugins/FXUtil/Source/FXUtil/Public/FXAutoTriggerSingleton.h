#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MultiFX2Handle.h"
#include "FXAutoTriggerAnyName.h"
#include "FXAutoTriggerRunningFXCollection.h"
#include "FXAutoTriggerSingleton.generated.h"

class UFXAutoTriggerDefinitionAsset;
class UFXAutoTriggerGlobalDefinitionAsset;
class UMaterialPermuterLoadingBundle;
class UObject;

UCLASS(Blueprintable, NotPlaceable, Transient)
class FXUTIL_API AFXAutoTriggerSingleton : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerGlobalDefinitionAsset* Globals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FFXAutoTriggerRunningFXCollection FX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, UMaterialPermuterLoadingBundle*> KeyMaterialBundles;
    
    AFXAutoTriggerSingleton(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetWorldCustomCondition(UObject* WorldContextObject, FName WorldConditionName, bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorCustomCondition(AActor* Actor, FName ActorConditionName, bool bEnabled);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RemoveManualActors(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, TArray<AActor*> Actors, bool& bResult);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RemoveManualActor(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, bool& bResult);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveCustomBucketActor(AActor* Actor, FName CustomBucket);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveActorByClass(AActor* Actor, UClass* ActorClass);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ManuallyTriggerPrerequisite(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, bool& bResult, bool bTrigger);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void KillAutoTriggerFX(UObject* WorldContextObject, UObject* FXOwner, UFXAutoTriggerDefinitionAsset* FXAutoTriggerDefinition, bool& bResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void IsManualPrerequisiteTriggered(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, bool& bResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void HasManualActor(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, bool& bResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void HasAutoTriggerFX(UObject* WorldContextObject, UObject* FXOwner, UFXAutoTriggerDefinitionAsset* FXAutoTriggerDefinition, bool& bResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetWorldCustomCondition(UObject* WorldContextObject, FName WorldConditionName, bool& bEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetEffectIsActive(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, bool& bIsActive);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetEffectHandle(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, FMultiFX2Handle& FXHandle);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetAnyEffectIsActive(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, bool& bAnyIsActive);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetActorCustomCondition(AActor* Actor, FName ActorConditionName, bool& bEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void EffectUpdatesDisabled(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, bool& bIsDisabled);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void EffectParameterUpdatesDisabled(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, FName Parameter, bool& bIsDisabled);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DisableEffectUpdates(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, bool bDisableUpdates, bool& bResult);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DisableEffectParameterUpdates(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, FName Parameter, bool bDisableUpdates, bool& bResult);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AddManualActors(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, TArray<AActor*> Actors, bool& bResult);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AddManualActor(UObject* WorldContextObject, FFXAutoTriggerAnyName FXName, AActor* Actor, bool& bResult);
    
    UFUNCTION(BlueprintCallable)
    static void AddCustomBucketActor(AActor* Actor, FName CustomBucket);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AddAutoTriggerFX(UObject* WorldContextObject, UObject* FXOwner, UFXAutoTriggerDefinitionAsset* FXAutoTriggerDefinition, bool& bResult);
    
    UFUNCTION(BlueprintCallable)
    static void AddActorByClass(AActor* Actor, UClass* ActorClass, FName ClassTag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ActorIsInCustomBucket(AActor* Actor, FName CustomBucket, bool& bIsIn);
    
};

