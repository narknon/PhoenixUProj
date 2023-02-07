#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Moddable.h"
#include "GameplayTagContainer.h"
#include "MunitionImpactData.h"
#include "EBossStates.h"
#include "EFlammableEnum.h"
#include "EImpactTypes.h"
#include "EMarkupType.h"
#include "ENoiseSize.h"
#include "EObjectSizeClass.h"
#include "EUIHealthBarType.h"
#include "EWidgetType.h"
#include "SavedMaterialsForMesh.h"
#include "Templates/SubclassOf.h"
#include "ObjectStateInfo.generated.h"

class AActor;
class AMunitionType_Base;
class UActorComponent;
class UAkAudioEvent;
class UAkComponent;
class UGeometryCollection;
class UMaterialPropertyData;
class UObjectStateDataContainerBase;
class UObjectStateInfo;
class UObjectStateInfoData;
class UOdcObstacleComponent;
class UParticleSystem;
class UPhoenixPhysicalMaterial;
class UPrimitiveComponent;
class URepairInfo;
class UStateEffectComponent;
class UStaticMesh;
class UVelocityTrackerComponent;

UCLASS(Blueprintable, Transient)
class PHOENIX_API UObjectStateInfo : public UObject, public IModdable {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRepair, AActor*, RepairedActor);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoved, AActor*, DestroyedActor);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnHealthChanged, AActor*, Target, float, InHealthChange, bool, bIndicateHUD);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnEspiskeyHealing, AActor*, Instigator, float, InHealthChange, AActor*, Target);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDestruct, AActor*, DestroyedActor);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnActorDamaged, AActor*, Target, AActor*, Instigator, float, Damage, const FHitResult&, Hit);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInWaterChangedDelegate, UObjectStateInfo*, ObjectStateInfo, bool, bOldInWater);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEndAffectingSpells);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDestruct OnDestruct;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRepair OnRepair;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHealthChanged OnHealthChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActorDamaged OnActorDamaged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEndAffectingSpells OnEndAffectingSpells;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnEspiskeyHealing OnEpiskeyHealing;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRemoved OnActorRemoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInWaterChangedDelegate InWaterChangedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EWidgetType WidgetType;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialPropertyData* MaterialPropertyData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSavedMaterialsForMesh> SavedMaterialForMeshArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObjectStateDataContainerBase* ObjectStateData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UActorComponent*> DynamicNavigationComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UOdcObstacleComponent* OdcObstacleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URepairInfo* RepairInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UOdcObstacleComponent* DynamicNavigationAreaObstacleComponent;
    
public:
    UObjectStateInfo();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WillRevealThruWalls() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WillNearDeathKneel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WasOnFireWhenKilled() const;
    
    UFUNCTION(BlueprintCallable)
    void UpdateUsability();
    
    UFUNCTION(BlueprintCallable)
    void UpdateActivation();
    
    UFUNCTION(BlueprintCallable)
    bool Unlock(float Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool TreatAsCharacterForDamage() const;
    
    UFUNCTION(BlueprintCallable)
    bool Thaw();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool TakeDamageFromCharacterCollisions() const;
    
    UFUNCTION(BlueprintCallable)
    bool ShouldCreateCrimescene(const AActor* Instigator);
    
    UFUNCTION(BlueprintCallable)
    void SetupSfx(UAkComponent* AkComponent);
    
    UFUNCTION(BlueprintCallable)
    void SetUnusable(float RestoreUsabilityTime);
    
    UFUNCTION(BlueprintCallable)
    void SetTransformable(bool bTransform);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetable(bool bTargetable);
    
    UFUNCTION(BlueprintCallable)
    void SetSpecialTargetPerceptionActive(bool bActive);
    
    UFUNCTION(BlueprintCallable)
    void SetSizeClass(EObjectSizeClass NewSizeClass);
    
    UFUNCTION(BlueprintCallable)
    void SetShowTargetUI(bool ShowUI);
    
    UFUNCTION(BlueprintCallable)
    void SetSendTargetPriority(uint8 Priority);
    
    UFUNCTION(BlueprintCallable)
    void SetRepairInPlace(bool bInPlace);
    
    UFUNCTION(BlueprintCallable)
    void SetRepairable(bool Repairable);
    
    UFUNCTION(BlueprintCallable)
    void SetProtectedFromDamageAndSpells(bool bInProtected, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void SetPersistence(bool InPersistence);
    
    UFUNCTION(BlueprintCallable)
    void SetPercentCharred(float PercentCharred);
    
    UFUNCTION(BlueprintCallable)
    void SetMinOptimumAvatarDistance(float Distance);
    
    UFUNCTION(BlueprintCallable)
    void SetMinDamageThreshold(float Threshold);
    
    UFUNCTION(BlueprintCallable)
    void SetMaxOptimumAvatarDistance(float Distance);
    
    UFUNCTION(BlueprintCallable)
    void SetMaterialSwapped(bool bInMaterialSwapped);
    
    UFUNCTION(BlueprintCallable)
    void SetMarkupValue(EMarkupType MarkupType, float InValue);
    
    UFUNCTION(BlueprintCallable)
    bool SetLocked();
    
    UFUNCTION(BlueprintCallable)
    void SetJuggernaut(bool bInJuggernaut);
    
    UFUNCTION(BlueprintCallable)
    void SetIsABoss(bool bInIsABoss);
    
    UFUNCTION(BlueprintCallable)
    void SetInWaterVolume(bool inWater);
    
    UFUNCTION(BlueprintCallable)
    void SetInWater(bool inWater, AActor* Instigator);
    
    UFUNCTION(BlueprintCallable)
    void SetInvulnerableToDamage(bool Invulnerable);
    
    UFUNCTION(BlueprintCallable)
    bool SetInvulnerable(float InInvulnerableTime);
    
    UFUNCTION(BlueprintCallable)
    void SetImpulseIgnoreTime(float Time);
    
    UFUNCTION(BlueprintCallable)
    void SetImmuneToSpells(bool bImmune);
    
    UFUNCTION(BlueprintCallable)
    void SetImmuneToEverythingExcept(const FGameplayTagContainer& InImpactTagContainer);
    
    UFUNCTION(BlueprintCallable)
    void SetHighlightWhenBroken(bool bHighlightWhenBroken);
    
    UFUNCTION(BlueprintCallable)
    void SetHidden(bool bHidden);
    
    UFUNCTION(BlueprintCallable)
    void SetHealthBarType(EUIHealthBarType InType);
    
    UFUNCTION(BlueprintCallable)
    bool SetHealth(float Amount, bool bIndicateHUD);
    
    UFUNCTION(BlueprintCallable)
    void SetFragile(bool Fragile);
    
    UFUNCTION(BlueprintCallable)
    void SetForceNotBroken(bool bNotBroken);
    
    UFUNCTION(BlueprintCallable)
    void SetForceBroken(bool bBroken);
    
    UFUNCTION(BlueprintCallable)
    void SetFlammable(EFlammableEnum InFlammable);
    
    UFUNCTION(BlueprintCallable)
    void SetExplode(bool bInExplode);
    
    UFUNCTION(BlueprintCallable)
    void SetEquipped(bool bInEquipped);
    
    UFUNCTION(BlueprintCallable)
    void SetDieInWater(bool DieInWater);
    
    UFUNCTION(BlueprintCallable)
    void SetDestructibleMeshByName(const FString& DestuctibleMeshName);
    
    UFUNCTION(BlueprintCallable)
    void SetDestructibleGeometryCollection(UGeometryCollection* DestructibleGeometryCollection);
    
    UFUNCTION(BlueprintCallable)
    void SetDestroyedBaseByName(const FString& BaseName);
    
    UFUNCTION(BlueprintCallable)
    void SetDestroyedBase(UStaticMesh* Base);
    
    UFUNCTION(BlueprintCallable)
    void SetDazed(bool bInDazed);
    
    UFUNCTION(BlueprintCallable)
    void SetDamagable(bool Damagable);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentlyTargeted(bool CurrentlyTargeted);
    
    UFUNCTION(BlueprintCallable)
    void SetCanHighlight(bool bCanHighlight);
    
    UFUNCTION(BlueprintCallable)
    void SetCanBecomeMovable(bool bCanBecomeMovable);
    
    UFUNCTION(BlueprintCallable)
    void SetBlocking(bool bInBlocking);
    
    UFUNCTION(BlueprintCallable)
    void SetBaseHealth(float Health);
    
    UFUNCTION(BlueprintCallable)
    void RestoreUsability(bool repeat);
    
    UFUNCTION(BlueprintCallable)
    void RestoreMaterial();
    
    UFUNCTION(BlueprintCallable)
    void Reset(bool bOriginalLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool RepairChildren() const;
    
    UFUNCTION(BlueprintCallable)
    void Repair(AActor* RepairInstigator, int32 Item, bool Aoe, bool InOriginalLocation, bool InAutoComplete);
    
    UFUNCTION(BlueprintCallable)
    void RemoveMagicEffects(const TArray<TSubclassOf<UStateEffectComponent>>& EffectTypeList);
    
    UFUNCTION(BlueprintCallable)
    void RemoveMagic();
    
    UFUNCTION(BlueprintCallable)
    void RemoveImmunity(const FGameplayTagContainer& InImpactTagContainer);
    
    UFUNCTION(BlueprintCallable)
    void RemoveImmuneUnlessCritical(const FGameplayTagContainer& InImpactTagContainer);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAllStateEffects();
    
    UFUNCTION(BlueprintCallable)
    void RemoveAllImmunity();
    
    UFUNCTION(BlueprintCallable)
    void RemoveAllImmuneUnlessCritical();
    
    UFUNCTION(BlueprintCallable)
    static void RemoveActorMagicEffects(AActor* InActor, const TArray<TSubclassOf<UStateEffectComponent>>& EffectTypeList);
    
    UFUNCTION(BlueprintCallable)
    void OnMunitionImpactDamage(const UObject* i_caller, const FMunitionImpactData& miData);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCurtainRaised();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable)
    void NotifyCriticalHit();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWaterproof() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUsableWhenRepaired() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUsable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUnusable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTransformable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargetableWhenBroken() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargetable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSpecialTargetPerceptionActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSimulatingPhysics() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRevelioResource() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsResurrecting() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRepairInPlace() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRepairing() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRepairable() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsProtectedFromDeath();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsProtectedFromDamageAndSpells() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsProtectedCompanion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPointOnFire(const FVector& Point, bool LimitToRing) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPetrified() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPartiallyBroken() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOnFire() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsObstacleDisabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsObjectTypeWater() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsObjectTypePlant() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsObjectTypeInanimate() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsObjectTypeAnimate() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNoDamageBreakable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNearDeathKneeling() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMovable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMounted() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMaterialSwapped() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLevitating() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInWaterVolume() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInWater() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInvulnerableToDamage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInvulnerable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInteractive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInNeedOfRepair() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsImperiousControlled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsImmuneToSpells() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsImmuneToFireDamage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsHidden() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsHealthZero() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsHealthCritical(bool bIgnorePendingDamage);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFrozen() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFreezable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFragile() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFlammable() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsFightClubOpponent();
    
    UFUNCTION(BlueprintCallable)
    static bool IsFallDamageDisabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEquipped() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDisillusioned() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDead() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDazed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDamagableWhenFrozen() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDamagableWhenCharred() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDamagableInPieces() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDamagable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCuttable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCursed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCrucioed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCommonBreakable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCombatCursed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCharred() const;
    
    UFUNCTION(BlueprintCallable)
    static bool IsCharacterOnGroundWithHitResult(const AActor* InActor, FHitResult& OutHitResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsCharacterOnGround(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBurning() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBrokenOrPartiallyBroken() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBroken() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBlocking() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsBeingAffectedBySpells();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAWolf() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAWizard() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsAwake();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsATroll() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsATransformedCharacter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAStudent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAStation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsASpider() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsArrestoMomentumed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsARagdoll() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAProtectedCharacterWhichCannotDie() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAProfessor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAPortraitCharacter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAPlayer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAPlant() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnOppugnoTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnInferi() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnEnvironment() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnEnemy() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsANamedCharacter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAMount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAMagicalCreatureWhichCannotDie() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAlly(const AActor* ActorPtr) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsALeader() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAJuggernaut() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAHouseElf() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAHobo() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAGoblin() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAGhost() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsADugbog() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsADragon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsADarkWizard() const;
    
    UFUNCTION(BlueprintCallable)
    static bool IsActorSimulatingPhysics(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static bool IsActorLeviosoActive(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsACreature() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsACompanion() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsACharacter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsACentaur() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsABossCharacter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsABiped() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IgnoreMunitionImpactEvents() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IgnoreLimitedCountRules() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IgnoreActorHitEvents() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasStateEffect() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasOnFireDoT() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasBecomeMovable() const;
    
    UFUNCTION(BlueprintCallable)
    bool HasAffectingSpells();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWetness() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UVelocityTrackerComponent* GetVelocityTracker() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetUIHealthPercent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetType() const;
    
    UFUNCTION(BlueprintCallable)
    static float GetTodaysPlayerGainedSoCapCount();
    
    UFUNCTION(BlueprintCallable)
    static float GetStudentsInInfirmary();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetStartAsleep() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSizeClassOnFireDestroyedDamage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<AMunitionType_Base> GetSizeClassOnFireDestroyedAOE() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSizeClassFireDamageMultiplier() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EObjectSizeClass GetSizeClass() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetShowTargetUI();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetSendTargetPriority() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRawCurrentHealth() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetRagdollInfo(FVector& Location, FVector& Velocity);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetRagdollBoneName() const;
    
    UFUNCTION(BlueprintCallable)
    static float GetPlayerPottedPlants();
    
    UFUNCTION(BlueprintCallable)
    static float GetPlayerFriendsCount();
    
    UFUNCTION(BlueprintCallable)
    static float GetPlayerEnemiesCount();
    
    UFUNCTION(BlueprintCallable)
    static float GetPlayerConsecutiveEnemyHits();
    
    UFUNCTION(BlueprintCallable)
    static float GetPlayerCompletedFactSheets();
    
    UFUNCTION(BlueprintCallable)
    bool GetPersistence();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPercentCharred() const;
    
    UFUNCTION(BlueprintCallable)
    static UObjectStateInfoData* GetObjectStateInfoData();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ENoiseSize GetObjectNoiseSize() const;
    
    UFUNCTION(BlueprintCallable)
    static float GetNormalHarvestCount();
    
    UFUNCTION(BlueprintCallable)
    static void GetNonScaledActorBounds(const AActor* InActor, bool bOnlyCollidingComponents, FVector& Origin, FVector& BoxExtent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetNeverAffectNavmesh() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetNavOverrideMobilityCheck() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMinOptimumAvatarDistance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMinDamageThreshold() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxOptimumAvatarDistance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxHealth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UMaterialPropertyData* GetMaterialPropertyData() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMarkupValue(EMarkupType MarkupType, float& OutValue) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLockValue() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLastDamageInReactionAdjustment() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetKilledWithAvadaKedavra() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EImpactTypes GetImpactType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAkAudioEvent* GetHitSfx() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealthPercentage() const;
    
    UFUNCTION(BlueprintCallable)
    EUIHealthBarType GetHealthBarType();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFrozenDamageMultiplier() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFireDamagePerSecond() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFireDamageFloor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAkAudioEvent* GetFastSfx() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetDisplayDamage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStaticMesh* GetDestroyedBase() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetDbVoiceId() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetDbTypeId() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetDbSubtypeID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetDbPersistentId() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetDbLookId() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetDbId() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetDbGenderId() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetDbEmoteVoiceId() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetDbClassId() const;
    
    UFUNCTION(BlueprintCallable)
    static float GetCursedEnemyCount();
    
    UFUNCTION(BlueprintCallable)
    bool GetCurrentlyTargeted();
    
    UFUNCTION(BlueprintCallable)
    static float GetCurrentItemEffectiveness();
    
    UFUNCTION(BlueprintCallable)
    static UPhoenixPhysicalMaterial* GetComponentPhoenixPhysicalMaterial(const UPrimitiveComponent* InPrimComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCompanionLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCharredDamageMultiplier() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetBrokenPieceLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EBossStates GetBossState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBaseHealth() const;
    
    UFUNCTION(BlueprintCallable)
    static float GetActorMass(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static UPrimitiveComponent* GetActorMainPrimitiveComponent(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static EImpactTypes GetActorImpactType(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetActor() const;
    
    UFUNCTION(BlueprintCallable)
    void ForceBreak(float InScale, bool InRestoreBroken);
    
    UFUNCTION(BlueprintCallable)
    void ForceAsleep();
    
    UFUNCTION(BlueprintCallable)
    void ExtendNearDeathKneel(float KneelTime);
    
    UFUNCTION(BlueprintCallable)
    bool EndAffectingSpells();
    
    UFUNCTION(BlueprintCallable)
    AActor* DropLootContainer(FVector InLocation);
    
    UFUNCTION(BlueprintCallable)
    AActor* DropCooldownPickup(FVector InLocation);
    
    UFUNCTION(BlueprintCallable)
    bool DoHealing(float Amount, AActor* InInstigator, UPrimitiveComponent* PrimComp, int32 Item, bool bAoe, bool InOriginalLocation, bool InAutoComplete);
    
    UFUNCTION(BlueprintCallable)
    bool DoFireDamage(float Amount, AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DoesExplode() const;
    
    UFUNCTION(BlueprintCallable)
    void DisableObjectState(bool bInDisabled);
    
    UFUNCTION(BlueprintCallable)
    static void DisableFallDamage(bool bDisable);
    
    UFUNCTION(BlueprintCallable)
    static void DisableDamageMods(bool bDisable);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DiesInWater() const;
    
    UFUNCTION(BlueprintCallable)
    void DelayedRestoreUsability(float Delay);
    
    UFUNCTION(BlueprintCallable)
    void DelayedRestoreBroken(float InTime);
    
    UFUNCTION(BlueprintCallable)
    void DelayedForceBreak(float InTime);
    
    UFUNCTION(BlueprintCallable)
    bool DecreaseWetness(float Amount);
    
    UFUNCTION(BlueprintCallable)
    bool DecreaseFire(float Amount);
    
    UFUNCTION(BlueprintCallable)
    void Deactivate();
    
    UFUNCTION(BlueprintCallable)
    void DamageInPieces(float InImpulseStr, float InDamage, const FVector& InHitLocation, const FVector& InHitDirection, float InRadius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void CreateNoise(ENoiseSize NoiseSize, const FVector& NoiseLocation, AActor* NoiseInstigator, FGameplayTagContainer EventContainer) const;
    
    UFUNCTION(BlueprintCallable)
    void ClearInvulnerable();
    
    UFUNCTION(BlueprintCallable)
    void ClearImmuneToEverythingExcept();
    
    UFUNCTION(BlueprintCallable)
    void ClearCurrentVelocity();
    
    UFUNCTION(BlueprintCallable)
    static void ClearCooldownPickupTargets();
    
    UFUNCTION(BlueprintCallable)
    void CheckObstacleSetup();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanHighlightWhenBroken() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanHighlight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanBeRepaired() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanBecomeMovable() const;
    
    UFUNCTION(BlueprintCallable)
    void BreakStaticDestructibleMesh(float InImpulseStr, const FVector& InHitLocation, const FVector& InHitDirection, UParticleSystem* InDestroyEffects, float InEffectRadius, float InRadius, float AdditionalDestructionForce, float AngularForceMultiplier);
    
    UFUNCTION(BlueprintCallable)
    void BecomeMovable(bool bBecomeMovable);
    
    UFUNCTION(BlueprintCallable)
    bool AdjustHealth(float change, bool bIndicateHUD);
    
    UFUNCTION(BlueprintCallable)
    void AddImmunity(const FGameplayTagContainer& InImpactTagContainer);
    
    UFUNCTION(BlueprintCallable)
    void AddImmuneUnlessCritical(const FGameplayTagContainer& InImpactTagContainer);
    
    UFUNCTION(BlueprintCallable)
    static void AddCooldownPickupTarget(const FVector& InTarget);
    
    UFUNCTION(BlueprintCallable)
    static void ActorStopSimulatingPhysics(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static void ActorStartSimulatingPhysics(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    void ActorHitShake(float Damage, const FVector& ImpactLocation);
    
    UFUNCTION(BlueprintCallable)
    void Activate();
    
    
    // Fix for true pure virtual functions not being implemented
};

