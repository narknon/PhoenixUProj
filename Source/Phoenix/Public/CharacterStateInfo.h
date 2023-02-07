#pragma once
#include "CoreMinimal.h"
#include "GameplayProperty_Float.h"
#include "GameplayProperty_Int.h"
#include "ChangedTeamsDelegateDelegate.h"
#include "FullHealthReachedDelegateDelegate.h"
#include "HealthThreshold.h"
#include "HealthThresholdReachedDelegateDelegate.h"
#include "NearDeathKneelBeginDelegateDelegate.h"
#include "NearDeathKneelEndDelegateDelegate.h"
#include "ObjectStateInfo.h"
#include "OnCriticalHealthChangedDelegateDelegate.h"
#include "OnVulnerabilityChangedDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "CharacterStateInfo.generated.h"

class AActor;
class UBonySkeletonComponent;
class UCharacterStateInfo;

UCLASS(Blueprintable, NonTransient)
class PHOENIX_API UCharacterStateInfo : public UObjectStateInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChangedTeamsDelegate ChangedTeamsDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnVulnerabilityChangedDelegate m_onVulnerabilityChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCriticalHealthChangedDelegate OnCriticalHealthChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNearDeathKneelBeginDelegate NearDeathKneelBeginDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNearDeathKneelEndDelegate NearDeathKneelEndDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFullHealthReachedDelegate FullHealthReachedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHealthThresholdReachedDelegate HealthThresholdReachedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* BlockingActor;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float OutgoingDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float DamageFocusModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float IncomingDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float OwnedPlantOutgoingDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float OwnedPlantIncomingDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float ImperiusControlledOutgoingDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float OppugnoOutgoingDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float LifeLeech;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float LifeLeechToCompanion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float LifeLeechToPlants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float BreakBlockChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float CriticalHitChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float SocapAmendModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float SocapDecayModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float SpellCooldownAmendModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float SpellCooldownReduction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float SpellCooldownAdditiveMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float EnemySpellCooldownModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float ItemEffectivenessModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float DoubleEffectivenessChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float MaxHealth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Float ThrownProjectileDistanceModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Int MaxActivePotionAbilities;
    
public:
    UCharacterStateInfo();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool WereSameTeam(const AActor* ActorPtr1, const AActor* ActorPtr2);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool WereAllies(const AActor* ActorPtr1, const AActor* ActorPtr2);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WasSameTeam(const AActor* ActorPtr) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WasAlly(const AActor* ActorPtr) const;
    
    UFUNCTION(BlueprintCallable)
    void StopIntervalHealthAdjust();
    
    UFUNCTION(BlueprintCallable)
    void StartIntervalHealthAdjust(float Interval, float Duration, float DeltaAmount);
    
    UFUNCTION(BlueprintCallable)
    void SetVulnerable(bool bInIsVulnerable);
    
    UFUNCTION(BlueprintCallable)
    void SetTeammateAllyOverride(bool bOverride);
    
    UFUNCTION(BlueprintCallable)
    static void SetTeamInteractionBetween(const AActor* InteractorActorPtr, const FName& InteracteeTeam, const FName& InInteraction, int32 Priority);
    
    UFUNCTION(BlueprintCallable)
    void SetTeamInteraction(const FName& InteracteeTeam, const FName& InInteraction, int32 Priority);
    
    UFUNCTION(BlueprintCallable)
    void SetTeam(const FName& InTeam);
    
    UFUNCTION(BlueprintCallable)
    void SetRegenerationRate(float Rate);
    
    UFUNCTION(BlueprintCallable)
    void SetProtegoActive(bool bProtegoActive);
    
    UFUNCTION(BlueprintCallable)
    void SetProtected(bool bInProtected);
    
    UFUNCTION(BlueprintCallable)
    static void SetOverrideNearDeathRecoverTime(float Time);
    
    UFUNCTION(BlueprintCallable)
    void SetLootable(bool bInLootable);
    
    UFUNCTION(BlueprintCallable)
    void SetIsAsleep(bool bInAsleep);
    
    UFUNCTION(BlueprintCallable)
    void SetInvincible(bool bInIsInvincible);
    
    UFUNCTION(BlueprintCallable)
    static void SetInteractionBetween(const AActor* InteractorActorPtr, const AActor* InteracteeActorPtr, const FName& InInteraction, int32 Priority);
    
    UFUNCTION(BlueprintCallable)
    void SetInteraction(const AActor* InteracteeActorPtr, const FName& InInteraction, int32 Priority);
    
    UFUNCTION(BlueprintCallable)
    void SetImperiusInstigator(AActor* InInstigatorPtr);
    
    UFUNCTION(BlueprintCallable)
    void SetImperiusCharTakesFullDamage(bool TakesFullDamage);
    
    UFUNCTION(BlueprintCallable)
    void SetIgnoreProtego(float Time);
    
    UFUNCTION(BlueprintCallable)
    void SetIgnoreAllyAttacks(bool Ignore);
    
    UFUNCTION(BlueprintCallable)
    void SetHealthThresholdArray(const TArray<FHealthThreshold>& HealthThresholdArray);
    
    UFUNCTION(BlueprintCallable)
    void SetDamageable(bool bAttackable);
    
    UFUNCTION(BlueprintCallable)
    void SetBlockingActor(AActor* InBlockingActor);
    
    UFUNCTION(BlueprintCallable)
    void SetAttackable(bool bAttackable);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorVulnerable(const AActor* InActor, bool bInIsVulnerable);
    
    UFUNCTION(BlueprintCallable)
    void SetActorToTeam(const AActor* DestActor, const AActor* SourceActor);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorInvincible(const AActor* InActor, bool bInIsInvincible);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorAttackable(const AActor* InActor, bool bInAttackable);
    
    UFUNCTION(BlueprintCallable)
    void SetActiveAuthorityFigure(bool bActive);
    
    UFUNCTION(BlueprintCallable)
    void RestoreLastTeam();
    
    UFUNCTION(BlueprintCallable)
    void RestoreInitialTeam();
    
    UFUNCTION(BlueprintCallable)
    void RestoreHealthToMax(const bool bRemoveTAK);
    
    UFUNCTION(BlueprintCallable)
    static void RestoreActorToLastTeam(const AActor* DestActor);
    
    UFUNCTION(BlueprintCallable)
    static void RestoreActorToInitialTeam(const AActor* DestActor);
    
    UFUNCTION(BlueprintCallable)
    static void ResetTeamInteractionBetween(const AActor* InteractorActorPtr, const FName& InteracteeTeam);
    
    UFUNCTION(BlueprintCallable)
    void ResetTeamInteraction(const FName& InteracteeTeam);
    
    UFUNCTION(BlueprintCallable)
    static void ResetInteractionBetween(const AActor* InteractorActorPtr, const AActor* InteracteeActorPtr);
    
    UFUNCTION(BlueprintCallable)
    void ResetInteraction(const AActor* InteracteeActorPtr);
    
    UFUNCTION(BlueprintCallable)
    static void ResetAllInteractionsFrom(const AActor* InteractorActorPtr);
    
    UFUNCTION(BlueprintCallable)
    void ResetAllInteractions();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsVulnerable() const;
    
    UFUNCTION(BlueprintCallable)
    static bool IsUnaware(const AActor* Source, const AActor* Target);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSameTeam(const AActor* ActorPtr) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsProtegoActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsProtected() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlayerSpawnableAlly(const AActor* ActorPtr);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLootable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInvincible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsIgnoringProtego() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDueling() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDamageable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAttackable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAsleep() const;
    
    UFUNCTION(BlueprintCallable)
    static bool IsActorVulnerable(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static bool IsActorInvincible(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static bool IsActorAttackable(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActiveAuthorityFigure() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ImmuneToFinisherDeath() const;
    
    UFUNCTION(BlueprintCallable)
    static bool HasInteractionBetween(const AActor* InteractorActorPtr, const AActor* InteracteeActorPtr);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasInteraction(const AActor* InteracteeActorPtr) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasChangedTeams() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetTeamInteraction(const AActor* InteracteeActorPtr, const FName& Team) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetTeam() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRegenerationRate() const;
    
    UFUNCTION(BlueprintCallable)
    static FString GetObjectClassName(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static float GetNumberOfHappyBeasts();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetLastTeam() const;
    
    UFUNCTION(BlueprintCallable)
    static FName GetInteractionBetween(const AActor* InteractorActorPtr, const AActor* InteracteeActorPtr);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetInteraction(const AActor* InteracteeActorPtr) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetInitialTeam() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetImperiusInstigator() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetImperiusCharTakesFullDamage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIgnoreAllyAttacks() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FHealthThreshold> GetHealthThresholdArray();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetGameEventRadius() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetEvilEffectiveness() const;
    
    UFUNCTION(BlueprintCallable)
    static FName GetEnemyInteractionWith(const AActor* InteractorActorPtr);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetEnemyInteraction(FName InInteractorTeam) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UCharacterStateInfo* GetCharacterStateInfo(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UBonySkeletonComponent> GetBonySkeleton() const;
    
    UFUNCTION(BlueprintCallable)
    AActor* GetBlockingActor();
    
    UFUNCTION(BlueprintCallable)
    static FName GetActorTeam(const AActor* DestActor);
    
    UFUNCTION(BlueprintCallable)
    static FName GetActorSubtypeID(const AActor* ActorPtr);
    
    UFUNCTION(BlueprintCallable)
    void EndNearDeathKneel();
    
    UFUNCTION(BlueprintCallable)
    static void ClearOverrideNearDeathRecoverTime();
    
    UFUNCTION(BlueprintCallable)
    void ClearIgnoreProtego();
    
    UFUNCTION(BlueprintCallable)
    void ChangeTeam(const FName& InTeam);
    
    UFUNCTION(BlueprintCallable)
    static void ChangeActorToTeam(const AActor* DestActor, const AActor* SourceActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool CanHitTarget(const AActor* Attacker, const AActor* Target);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AreSameTeam(const AActor* ActorPtr1, const AActor* ActorPtr2);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AreAllies(const AActor* ActorPtr1, const AActor* ActorPtr2);
    
};

