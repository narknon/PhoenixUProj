#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "BossFightData.h"
#include "CharacterMount_Interface.h"
#include "Enemy_Character_Interface.h"
#include "FireInterface.h"
#include "HealthThreshold.h"
#include "NPC_Character.h"
#include "OnClothTargetsEndDelegate.h"
#include "OnClothTargetsStartDelegate.h"
#include "PostChangeTeamDelegate.h"
#include "Enemy_Character.generated.h"

class AActor;
class ACombatVolume;
class ADynamicObjectVolume;
class UBTCustomComponent;
class UCognitionStimuliSourceComponent;
class UEnemyAIComponent;
class UEnemyStateComponent;
class UEnemy_AttackComponent;
class UEnemy_WeaponComponent;
class UObjectArchitectAsset;
class UToolSetComponent;

UCLASS(Blueprintable)
class PHOENIX_API AEnemy_Character : public ANPC_Character, public IEnemy_Character_Interface, public IFireInterface, public ICharacterMount_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRegisterPerceptionAfterSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FinisherHealthPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PlayerStupifyHits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UToolSetComponent* ToolSetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* CognitionStimuliSourceComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyAIComponent* EnemyAIComponent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyStateComponent* EnemyStateComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBTCustomComponent* BehaviorCompAttackUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemy_AttackComponent* AttackComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemy_WeaponComponent* WeaponComponent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostChangeTeam OnChangeTeam;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObjectArchitectAsset* VfxObjectArchitectAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ObjectArchitectEnemyClassTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ObjectArchitectEnemyFactionTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ADynamicObjectVolume* SpawningDOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ACombatVolume*> OccupiedCombatVolumes;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOnClothTargetsStart ClothTargetsStartDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOnClothTargetsEnd ClothTargetsEndDelegate;
    
public:
    AEnemy_Character(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateBossStateEvent(FBossFightData InBossFightData);
    
    UFUNCTION(BlueprintCallable)
    static void UnhideAndEnableEnemyCharacter(AActor* EnemyCharacter);
    
    UFUNCTION(BlueprintCallable)
    void Throw(AActor* Target, AActor* SourceActor);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool StartFire(float Amount, FVector Location);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetAsLeader(bool bSet);
    
    UFUNCTION(BlueprintCallable)
    void SetAsGroupAggressor(bool bSet, FName InNewTeamName);
    
    UFUNCTION(BlueprintCallable)
    void SetAsFightClubOpponent(bool bSet, FName InNewTeamName, FName InAudioSubtypeID);
    
    UFUNCTION(BlueprintCallable)
    void SetAsDuelOpponent(bool bSet, FName InAudioSubtypeID);
    
    UFUNCTION(BlueprintCallable)
    void SetAsCompanion(bool bSet);
    
    UFUNCTION(BlueprintCallable)
    void SetAsAggressor(bool bSet, FName InNewTeamName);
    
    UFUNCTION(BlueprintCallable)
    void OnTakeAKneeTimedOut();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFireExtinguished();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCompletelyCharred();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void MunitionCreated();
    
    UFUNCTION(BlueprintCallable)
    void Landed(const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLeader() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDuelOpponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCompanion() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCombatOpponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAggressor() const;
    
    UFUNCTION(BlueprintCallable)
    static void HideAndDisableEnemyCharacter(AActor* EnemyCharacter);
    
    UFUNCTION(BlueprintCallable)
    void HandleNearDeathKneelStart(AActor* ActorKneeling);
    
    UFUNCTION(BlueprintCallable)
    void HandleNearDeathKneelEnd();
    
    UFUNCTION(BlueprintCallable)
    void HandleMeleeHit(AActor* Victim, const FVector& NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable)
    void HandleHealthThresholdReached(FHealthThreshold InHealthThreshold, int32 InLevel, int32 InMaxLevel);
    
    UFUNCTION(BlueprintCallable)
    void ExitSpline();
    
    UFUNCTION(BlueprintCallable)
    bool ChangeTeamWithCombat(const FName TeamName, const bool bEnableCombat);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AttackWindowStop();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AttackWindowStart();
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    void SetClothTargetsStartDelegate(const FOnClothTargetsStart& Delegate) override PURE_VIRTUAL(SetClothTargetsStartDelegate,);
    
    UFUNCTION(BlueprintCallable)
    void SetClothTargetsEndDelegate(const FOnClothTargetsEnd& Delegate) override PURE_VIRTUAL(SetClothTargetsEndDelegate,);
    
};

