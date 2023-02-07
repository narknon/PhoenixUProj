#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "CameraFXRoot.h"
#include "WorldFXGenericManageSettings.h"
#include "WorldFXOctreeStack.h"
#include "WorldFXPerWorldSettings.h"
#include "WorldFXPresetRuleName.h"
#include "WorldFXSimpleCullDistance.h"
#include "WorldFXSpawnOverrides.h"
#include "WorldFXSingleton.generated.h"

class IWorldFXInterface;
class UWorldFXInterface;
class UActorComponent;
class UAkComponent;
class UNiagaraComponent;
class UObject;
class UParticleSystemComponent;
class UWorldFXOctreeFX;
class UWorldFXOctreeFXDummy;
class UWorldFXRule;

UCLASS(Blueprintable, NotPlaceable, Transient)
class WORLDFX_API AWorldFXSingleton : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXPerWorldSettings Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCameraFXRoot CameraFXRoot;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWorldFXOctreeStack Octree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bCullingDisabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 AutoCascadeCullingLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 AutoNiagaraCullingLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 AutoAkAmbientCullingLevel;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<TWeakObjectPtr<AActor>> AutoManagedActors;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TSet<TWeakObjectPtr<UActorComponent>> AutoManagedComponents;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TSet<TWeakObjectPtr<UActorComponent>> ManualManagedComponents;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UObject>, TWeakObjectPtr<UWorldFXOctreeFX>> WorldFXInterfaces;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWorldFXOctreeFXDummy* FXOctreeFXDummy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector LastEye;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bLastEyeValid;
    
public:
    AWorldFXSingleton();
    UFUNCTION(BlueprintCallable)
    static bool UnregisterWorldFXInterface(TScriptInterface<IWorldFXInterface> WorldFXInterface);
    
    UFUNCTION(BlueprintCallable)
    static bool RegisterWorldFXInterface(TScriptInterface<IWorldFXInterface> WorldFXInterface, FVector Position, FWorldFXSimpleCullDistance CullDistance, const UWorldFXRule* Rule, float ExtraRadius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void PresetRuleExists(FWorldFXPresetRuleName PresetName, bool& bResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void PresetRuleEvaluateWithSpawnParameters(UObject* WorldContextObject, FWorldFXPresetRuleName PresetName, FVector FXSpawnPosition, FWorldFXSpawnOverrides& SpawnOverrides, bool& bResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void PresetRuleEvaluate(UObject* WorldContextObject, FWorldFXPresetRuleName PresetName, FVector FXSpawnPosition, bool& bResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void IsWorldFXInterfaceRegistered(TScriptInterface<IWorldFXInterface> WorldFXInterface, bool& bIsRegistered);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UWorldFXRule* GetPresetRule(FWorldFXPresetRuleName PresetRuleName);
    
    UFUNCTION(BlueprintCallable)
    static void ForgetManagedNiagaraComponent(UNiagaraComponent* NiagaraComponent);
    
    UFUNCTION(BlueprintCallable)
    static void ForgetManagedGenericComponent(UActorComponent* ActorComponent);
    
    UFUNCTION(BlueprintCallable)
    static void ForgetManagedCascadeComponent(UParticleSystemComponent* ParticleSystemComponent);
    
    UFUNCTION(BlueprintCallable)
    static void ForgetManagedAudioComponent(UAkComponent* AudioComponent);
    
    UFUNCTION(BlueprintCallable)
    static void AutoManageNiagaraComponent(UNiagaraComponent* NiagaraComponent, float CullDistanceMeters);
    
    UFUNCTION(BlueprintCallable)
    static void AutoManageGenericComponent(UActorComponent* ActorComponent, FWorldFXGenericManageSettings Manage, float CullDistanceMeters);
    
    UFUNCTION(BlueprintCallable)
    static void AutoManageCascadeComponent(UParticleSystemComponent* ParticleSystemComponent, float CullDistanceMeters);
    
    UFUNCTION(BlueprintCallable)
    static void AutoManageAudioComponent(UAkComponent* AudioComponent, float CullDistanceMeters);
    
};

