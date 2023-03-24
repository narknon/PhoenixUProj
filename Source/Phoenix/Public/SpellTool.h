#pragma once
#include "CoreMinimal.h"
#include "BTCustomAction.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "MunitionImpactData.h"
#include "Tool.h"
#include "AbilityFunction.h"
#include "EAttackState.h"
#include "EGameEventLocation.h"
#include "EGameEvent_Intensity.h"
#include "EImpactTypes.h"
#include "ELeftArmState.h"
#include "ERightArmState.h"
#include "ESpellCategory.h"
#include "ESpellUpgrades.h"
#include "ImpactLevelData.h"
#include "Templates/SubclassOf.h"
#include "SpellTool.generated.h"

class AActor;
class ACharacter;
class AMunitionType_Base;
class AWandTool;
class UAblReactionComponent;
class UAblReactionData;
class UActorComponent;
class UAkAudioEvent;
class UAkComponent;
class UInteractionArchitectAsset;
class ULEDFadeEffect;
class UMaterialInterface;
class UMultiFX2_Base;
class USceneComponent;
class USpellToolRecord;
class UStateEffectComponent;
class UTriggerEffect;

UCLASS(Blueprintable)
class ASpellTool : public ATool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBTCustomAction SpellStartAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBTCustomAction SpellStopAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UClass*> ExecutionClassMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHeavyCast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ELeftArmState::Type> LeftArmState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ERightArmState::Type> RightArmState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> PrepMuzzleFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* PrepMuzzleMotionFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKillPrepFXWhenMuzzleFXStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> MuzzleFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* MuzzleMotionFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* EndMuzzleMotionFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> ProjectileFiredFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ProjectileFiredFX2EndsWithMunition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* ProjectileMotionFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* ProjectileSfx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FImpactLevelData> ImpactLevelDataArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlaceDecal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DecalMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DecalSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DecalFadeInDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DecalFadeInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DecalLifeSpan;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DecalFadeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DecalRandomOrientation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* Decal3D;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Decal3DRandomOrientation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> DestroyedPieceFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DestroyedPieceFXRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameEventLocation GameEventLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameEventTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameEvent_Intensity GameEventIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GameEventDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GameEventRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GameEventFalloff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DatabaseName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MunitionTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* MunitionDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer EndMunitionTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAttackState::Type> AttackState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* SpellImpactComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayStateTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> StateEffectFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UStateEffectComponent>> TerminatePreviousEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableCCDOnTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreSpawnMunitionDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bActivateAllPerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAbilityFunction> AbilityFunctions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAoe;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAOEAtTargetLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAffectTeammates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyAffectsMovable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanAffectBroken;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanAffectPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetWandCastTargetTrackers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AMunitionType_Base>> DeflectMunitionActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SpawnAllDeflectMunitionActors;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AMunitionType_Base> LastMunitionFired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayersUseImprovedTargeting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTriggerEffect> SpellActiveTriggerEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ULEDFadeEffect> PrepLEDEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ULEDFadeEffect> StartLEDEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ULEDFadeEffect> EndLEDEffect;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* OverrideSourceActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* OverrideTargetActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* OverrideTargetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* OverrideCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AMunitionType_Base*> CachedMunitionArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* LevelDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UActorComponent* ImpactComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTriggerEffect* pSpellActiveTriggerEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAffectsRightTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAffectsLeftTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULEDFadeEffect* pPrepLEDEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULEDFadeEffect* pStartLEDEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULEDFadeEffect* pEndLEDEffect;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* ProjectileAkComponent;
    
public:
    ASpellTool(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TriggerReleased(bool bForce, bool bFromStop);
    
    UFUNCTION(BlueprintCallable)
    void StopActive();
    
    UFUNCTION(BlueprintCallable)
    void StartChannelingAction();
    
    UFUNCTION(BlueprintCallable)
    bool Start();
    
    UFUNCTION(BlueprintCallable)
    void SpellFlourish();
    
    UFUNCTION(BlueprintCallable)
    void SetIgnoreActors(TArray<AActor*> i_Ignores);
    
    UFUNCTION(BlueprintCallable)
    void SetDestinationActor(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    void SetAffectImmuneToSpells(bool bAffectImmune);
    
    UFUNCTION(BlueprintCallable)
    static void ReassignBeamTarget(const AActor* CurrentActor, USceneComponent* NewComponent);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ReactionStart(UAblReactionData* InReactionData, UAblReactionComponent* ReactionComponent);
    
    UFUNCTION(BlueprintCallable)
    void ReactionEnd(UAblReactionData* InReactionData, UAblReactionComponent* ReactionComponent);
    
public:
    UFUNCTION(BlueprintCallable)
    void PreSpawnMunition();
    
    UFUNCTION(BlueprintCallable)
    void Prep();
    
protected:
    UFUNCTION(BlueprintCallable)
    void PlayHitActorFX(const FHitResult& HitResult);
    
public:
    UFUNCTION(BlueprintCallable)
    void OwnerHasStartedCasting(FName WandCastName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStop();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnProtegoBlocked(AMunitionType_Base* InMunitionInstance, AActor* Target, const FHitResult& Hit, FVector ImpactDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPrep();
    
    UFUNCTION(BlueprintCallable)
    void OnMunitionOverlap(AMunitionType_Base* MunitionInstance, const FMunitionImpactData& MunitionImpactData);
    
    UFUNCTION(BlueprintCallable)
    void OnMunitionImpactDamage(AMunitionType_Base* MunitionInstance, const FMunitionImpactData& MunitionImpactData);
    
    UFUNCTION(BlueprintCallable)
    void OnMunitionImpact(AMunitionType_Base* MunitionInstance, const FMunitionImpactData& MunitionImpactData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnMunitionFired(AActor* Target, FVector TargetLocation, AMunitionType_Base* BaseMunition, const FGameplayTagContainer& InMunitionTagContainer);
    
    UFUNCTION(BlueprintCallable)
    void OnMunitionDestroyed(AMunitionType_Base* InMunitionInstance);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFizzle();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCastSpell(AActor* Target, const FVector& Location, const FVector& MuzzleLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCanAffectTarget(AActor* Target, bool bInCanAffectTarget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAffectTarget(AActor* Target, USceneComponent* Component, bool bInTargetAffected);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsToolUsedByPlayer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStopped() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStarted_K2() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsChanneling() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBeastCaptureSpell() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasUpgradedMechanics() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasUpgrade(ESpellUpgrades Upgrade) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AWandTool* GetWand() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetSpellType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USpellToolRecord* GetSpellToolRecord() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ESpellCategory GetSpellCategory() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetSourceActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetProjectileSpeed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetMuzzleLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<AMunitionType_Base> GetMunitionActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxRange() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EImpactTypes GetImpactType() const;
    
    UFUNCTION(BlueprintCallable)
    UClass* GetExecutionClassFromKeyWord(FName KeyWord);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDuration(bool bTargetIsACharacter) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetCharacterActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter* GetCharacter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetActiveTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AMunitionType_Base* GetActiveMunition() const;
    
    UFUNCTION(BlueprintCallable)
    void ForceStop();
    
    UFUNCTION(BlueprintCallable)
    void FireOnHitBySpell(AActor* InTargetActor, AActor* InInstigator, const FGameplayTagContainer& InMunitionTagContainer, const FHitResult& HitResult, const FVector& ImpactDirection);
    
    UFUNCTION(BlueprintCallable)
    void Failed_K2();
    
    UFUNCTION(BlueprintCallable)
    void EndToggleSpell(bool bForcedExternally);
    
    UFUNCTION(BlueprintCallable)
    UActorComponent* CreateImpactComponent(AActor* InTargetActor, const FMunitionImpactData& InMunitionImpactData);
    
    UFUNCTION(BlueprintCallable)
    float CalculateCharacterDamage(AActor* InTarget, bool& OutWillKillTarget);
    
    UFUNCTION(BlueprintCallable)
    static bool BreaksShield(const AActor* Target, const FGameplayTagContainer& InTagContainer);
    
    UFUNCTION(BlueprintCallable)
    void Abort();
    
};

