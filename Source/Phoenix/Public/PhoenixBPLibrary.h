#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Curves/CurveLinearColor.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RuntimeCurveVector -FallbackName=RuntimeCurveVector
#include "Curves/CurveFloat.h"
#include "HermesBPDelegateHandle.h"
#include "DamageResult.h"
#include "EEnemy_ParryButtonPressed.h"
#include "Enemy_ParryTimeToImpactData.h"
#include "Enemy_ParryWindowBeginData.h"
#include "Enemy_ParryWindowEndData.h"
#include "GameplayTagContainerWrapper.h"
#include "HitBySpellData.h"
#include "HouseIds.h"
#include "InventoryResult.h"
#include "LockManagerLock.h"
#include "RuntimeCurveVector.h"
#include "SpellForce.h"
#include "PhoenixBPLibrary.generated.h"

class AActor;
class UActorComponent;
class UForceResidentStreamableRenderAssetCollectionWrapper;
class UGearAppearanceItemDefinition;
class UObject;
class USceneComponent;
class USkeletalMeshComponent;
class UStationComponent;
class UWorld;

UCLASS(Blueprintable)
class PHOENIX_API UPhoenixBPLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesStationComponentDelegate, const UObject*, Caller, const UStationComponent*, StationComponent);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesSpellForceDelegate, const UObject*, Caller, const FSpellForce&, SpellForce);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesReflectAttackDelegate, const UObject*, Caller, const FDamageResult&, DamageResult);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesParryWindowEndDelegate, const UObject*, Caller, const FEnemy_ParryWindowEndData&, ParryWindowEndData);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesParryWindowBeginDelegate, const UObject*, Caller, const FEnemy_ParryWindowBeginData&, ParryWindowBeginData);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesParryTimeToImpactDelegate, const UObject*, Caller, const FEnemy_ParryTimeToImpactData&, ParryTimeToImpactData);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesParryEventDelegate, const UObject*, Caller, EEnemy_ParryButtonPressed, ButtonPressed);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesLockDelegate, const UObject*, Caller, const FLockManagerLock&, Lock);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesInventoryResultDelegate, const UObject*, Caller, const FInventoryResult&, InventoryResult);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesDamageResultDelegate, const UObject*, Caller, const FDamageResult&, DamageResult);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesActorHitBySpellDelegate, const UObject*, Caller, const FHitBySpellData&, HitBySpell);
    
    UPhoenixBPLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void VerifyKey(const TArray<FString>& Keys);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorId(AActor* Actor, FName ActorId);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSoftObjectPtr<UObject> MakeSoftObjectReferenceFromPath(const FSoftObjectPath& Path);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSoftObjectPtr<UObject> MakeSoftObjectReference(const FString& PathString);
    
    UFUNCTION(BlueprintCallable)
    static UForceResidentStreamableRenderAssetCollectionWrapper* LoadGearAppearanceItemDefinitionLODs(UWorld* World, TArray<UGearAppearanceItemDefinition*> GearAppearanceItemDefinitions, bool bIncludeTextures);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsRegexMatch(const FString& Pattern, const FString& Input);
    
    UFUNCTION(BlueprintCallable)
    static bool IsItemOwned(const FString& ProductID);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedStationComponent(const FString& Name, const UObject* Owner, const UObject* Caller, const UStationComponent* StationComponent);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedSpellForce(const FString& Name, const UObject* Owner, const UObject* Caller, const FSpellForce& SpellForce);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedReflectAttack(const FString& Name, const UObject* Owner, const UObject* Caller, const FDamageResult& DamageResult);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedParryWindowEnd(const FString& Name, const UObject* Owner, const UObject* Caller, const FEnemy_ParryWindowEndData& ParryWindowEndData);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedParryWindowBegin(const FString& Name, const UObject* Owner, const UObject* Caller, const FEnemy_ParryWindowBeginData& ParryWindowBeginData);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedParryTimeToImpact(const FString& Name, const UObject* Owner, const UObject* Caller, const FEnemy_ParryTimeToImpactData& ParryTimeToImpactData);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedParryEvent(const FString& Name, const UObject* Owner, const UObject* Caller, EEnemy_ParryButtonPressed ButtonPressed);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedLock(const FString& Name, const UObject* Owner, const UObject* Caller, const FLockManagerLock& Lock);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedInventoryResult(const FString& Name, const UObject* Owner, const UObject* Caller, const FInventoryResult& InventoryResult);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedDamageResult(const FString& Name, const UObject* Owner, const UObject* Caller, const FDamageResult& DamageResult);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwnedActorHitBySpell(const FString& Name, const UObject* Owner, const UObject* Caller, const FHitBySpellData& HitBySpell);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllStationComponent(const FString& Name, const UObject* Caller, const UStationComponent* StationComponent);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllSpellForce(const FString& Name, const UObject* Caller, const FSpellForce& SpellForce);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllReflectAttack(const FString& Name, const UObject* Caller, const FDamageResult& DamageResult);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllParryWindowEnd(const FString& Name, const UObject* Caller, const FEnemy_ParryWindowEndData& ParryWindowEndData);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllParryWindowBegin(const FString& Name, const UObject* Caller, const FEnemy_ParryWindowBeginData& ParryWindowBeginData);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllParryTimeToImpact(const FString& Name, const UObject* Caller, const FEnemy_ParryTimeToImpactData& ParryTimeToImpactData);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllParryEvent(const FString& Name, const UObject* Caller, EEnemy_ParryButtonPressed ButtonPressed);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllLock(const FString& Name, const UObject* Caller, const FLockManagerLock& Lock);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllInventoryResult(const FString& Name, const UObject* Caller, const FInventoryResult& InventoryResult);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllGameplayTags(const FString& Name, const UObject* Caller, const FGameplayTagContainerWrapper& Wrapper);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllDamageResult(const FString& Name, const UObject* Caller, const FDamageResult& DamageResult);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAllActorHitBySpell(const FString& Name, const UObject* Caller, const FHitBySpellData& HitBySpell);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindStationComponent(UPhoenixBPLibrary::FHermesStationComponentDelegate Delegate_StationComponent, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindSpellForce(UPhoenixBPLibrary::FHermesSpellForceDelegate Delegate_MunitionImpactData, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindReflectAttack(UPhoenixBPLibrary::FHermesReflectAttackDelegate Delegate_ReflectAttack, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindParryWindowEnd(UPhoenixBPLibrary::FHermesParryWindowEndDelegate Delegate_ActorParryWindowEnd, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindParryWindowBegin(UPhoenixBPLibrary::FHermesParryWindowBeginDelegate Delegate_ActorParryWindowBegin, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindParryTimeToImpact(UPhoenixBPLibrary::FHermesParryTimeToImpactDelegate Delegate_ActorParryTimeToImpact, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindParryEvent(UPhoenixBPLibrary::FHermesParryEventDelegate Delegate_ActorParryEvent, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindLock(UPhoenixBPLibrary::FHermesLockDelegate Delegate_Lock, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindInventoryResult(UPhoenixBPLibrary::FHermesInventoryResultDelegate Delegate_InventoryResult, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindDamageResult(UPhoenixBPLibrary::FHermesDamageResultDelegate Delegate_DamageResult, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindActorHitBySpell(UPhoenixBPLibrary::FHermesActorHitBySpellDelegate Delegate_ActorHitBySpell, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static FVector GetRuntimeVectorCurveValue(const FRuntimeCurveVector& Curve, float Time);
    
    UFUNCTION(BlueprintCallable)
    static FLinearColor GetRuntimeLinearColorCurveValue(const FRuntimeCurveLinearColor& Curve, float Time);
    
    UFUNCTION(BlueprintCallable)
    static float GetRuntimeFloatCurveValue(const FRuntimeFloatCurve& Curve, float Time);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TEnumAsByte<HouseIds> GetObjectHouseID(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<HouseIds> GetHouseEnumFromHouseID(const FString& InHouseID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FRotator GetDisillusionmentEyeRotation(FName ParentSocket, USceneComponent* Mesh, const FVector& TargetLocation, const float MaxHorizontalAngle, const float MaxVerticalAngle);
    
    UFUNCTION(BlueprintCallable)
    static FString GetActorName(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static bool GetActorId(const AActor* Actor, FName& OutActorId);
    
    UFUNCTION(BlueprintCallable)
    static void ForceUpdateTextureMips(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static void DestroyComponent(UActorComponent* Component, bool bPromoteChildren);
    
    UFUNCTION(BlueprintCallable)
    void CultureChanged();
    
    UFUNCTION(BlueprintCallable)
    static bool ChangeOutfit(AActor* Actor, TArray<FName> GearIDs, TArray<USkeletalMeshComponent*>& OldMeshes, TArray<USkeletalMeshComponent*>& NewMeshes, bool bSkipChangingGear);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSoftObjectPtr<UWorld> CastToWorldSoftObjectReference(TSoftObjectPtr<UObject> ObjRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText AVATranslateSubtitle(const FString& Key, const FString& DebugLogText);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText AVATranslate(const FString& Key, const FString& DebugLogText);
    
    UFUNCTION(BlueprintCallable)
    static bool AvaIsRunningWithEditor();
    
    UFUNCTION(BlueprintCallable)
    static bool AvaIsRunningCommandlet();
    
};

