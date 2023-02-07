#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "CompanionFollowParams.h"
#include "CompanionSettingData.h"
#include "CompanionVolumeEntry.h"
#include "CompanionVolumeSettings.h"
#include "EVoiceOverCompanionSelection.h"
#include "EVoiceOverConditions.h"
#include "Templates/SubclassOf.h"
#include "CompanionManager.generated.h"

class AActor;
class AAmbulatory_Character;
class APawn;
class UAblAbility;
class UCompanionConfigData;
class UCompanionManager;
class UScheduledEntity;

UCLASS(Blueprintable)
class PHOENIX_API UCompanionManager : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCompanionConfigData* Config;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCompanionVolumeEntry> CompanionSettingsVolumesPerEntity;
    
public:
    UCompanionManager();
    UFUNCTION(BlueprintCallable)
    static bool TryCompanionTeleportBP(UScheduledEntity* ScheduledEntity, const FVector& TargetLocation, const FRotator& TargetRotation);
    
    UFUNCTION(BlueprintCallable)
    bool TryCompanionTeleportBehindPlayer();
    
    UFUNCTION(BlueprintCallable)
    void TryCompanionPlayerRescue();
    
    UFUNCTION(BlueprintCallable)
    void StopPrimaryCompanionCustomAbility();
    
    UFUNCTION(BlueprintCallable)
    void StopMovement(const bool InStopMovement);
    
    UFUNCTION(BlueprintCallable)
    void StopCompanionForcedWaiting();
    
    UFUNCTION(BlueprintCallable)
    void StartPrimaryCompanionCustomAbility(TSubclassOf<UAblAbility> Ability);
    
    UFUNCTION(BlueprintCallable)
    void StartFadeOut();
    
    UFUNCTION(BlueprintCallable)
    void StartFadeIn();
    
    UFUNCTION(BlueprintCallable)
    static void SetSystemicCompanionBP(const FString& Name, const bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    static void SetCompanionSettingDataToConfigBP(const FString& Name);
    
    UFUNCTION(BlueprintCallable)
    static void SetCompanionSettingDataBP(const FString& Name, const FCompanionSettingData InCompanionSettingData);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetCompanionIsIdleFlag(AActor* InCompanionActor, const bool InBCompanionIsIdle);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetCompanionForcedWaitLocation(const FVector& InWaitLocation, const FVector& InWaitDirection);
    
    UFUNCTION(BlueprintCallable)
    static void SetCompanionBP(const FString& Name, const bool bEnable);
    
protected:
    UFUNCTION(BlueprintCallable)
    void RestoreCompanionHealth();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void PlayVoiceOverForPawn(const FString& VOEventName, APawn* Pawn) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool PlayVoiceOver(const FString& VOEventName, EVoiceOverCompanionSelection Selection, EVoiceOverConditions Condition) const;
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerEnterLeaveCompanionSettingsVolume(const AActor* Volume, const FCompanionVolumeSettings& Settings, bool bInside);
    
    UFUNCTION(BlueprintCallable)
    void OnPawnEnterLeaveCompanionSettingsVolume(const AActor* Volume, const APawn* Pawn, const FCompanionVolumeSettings& Settings, bool bInside);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCompanionRemoved(AActor* Companion);
    
    UFUNCTION(BlueprintCallable)
    void OnCompanionReady(const UScheduledEntity* companionScheduledEntity);
    
    UFUNCTION(BlueprintCallable)
    void OnCompanionHealing(AActor* Instigator, float InHealthChange, AActor* TargetActor);
    
    UFUNCTION(BlueprintCallable)
    void OnCompanionDismissed(FName CompanionName);
    
    UFUNCTION(BlueprintCallable)
    void OnCompanionDied(AActor* Companion);
    
    UFUNCTION(BlueprintCallable)
    void OnCompanionDamaged(AActor* InActor, AActor* InInstigator, float InDamage, const FHitResult& InHit);
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterTeleported(AAmbulatory_Character* TeleportedCharacter, FVector AmountDisplaced, FRotator AmountRotated);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnAboutToSaveGame();
    
protected:
    UFUNCTION(BlueprintCallable)
    bool MoveToLocation(const FVector InCharacterLocation, APawn* InCompanionPawn);
    
public:
    UFUNCTION(BlueprintCallable)
    static bool IsCompanionWaitingBP(const APawn* Pawn, FVector& WaitLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCharacterCompanion(UScheduledEntity* entity) const;
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> IdentitiesAllowedToAddOnCompanion(const FName& InCompanionName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasPrimaryFollowingCompanion() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasPrimaryCompanion() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasCompanionToRescuePlayer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAnyCompanion() const;
    
    UFUNCTION(BlueprintCallable)
    void HandleFleshLoaded(AActor* FleshActor);
    
    UFUNCTION(BlueprintCallable)
    static void HandleCompanionInteractionBP(const int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void HandleActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpluse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetUnlockedSystemicCompanions() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APawn* GetPrimaryCompanionPawn() const;
    
    UFUNCTION(BlueprintCallable)
    FName GetPrimaryCompanionNameBP();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetForcedCompanionName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetDisabledSystemicCompanions() const;
    
    UFUNCTION(BlueprintCallable)
    static bool GetCompanionSettingDataFromActorBP(const AActor* companionActor, FCompanionSettingData& OutCompanionSettingData);
    
    UFUNCTION(BlueprintCallable)
    static bool GetCompanionSettingDataBP(const FString& Name, FCompanionSettingData& OutCompanionSettingData);
    
protected:
    UFUNCTION(BlueprintCallable)
    FName GetCompanionNameWithMostCompanionshipTime();
    
public:
    UFUNCTION(BlueprintCallable)
    static UCompanionManager* GetCompanionManager();
    
    UFUNCTION(BlueprintCallable)
    static FString GetCompanionInteractionTextBP(AActor* interactionActor, const int32 Index);
    
    UFUNCTION(BlueprintCallable)
    static bool GetCompanionFollowParamsBP(const APawn* Pawn, FCompanionFollowParams& Params);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetAllPossibleSystemicCompanions() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetActivePrimaryCompanionPawnAndName(APawn*& CompanionPawn, FName& OutCompanionName, bool bIsFemale) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetActivePrimaryCompanionPawn(APawn*& CompanionPawn) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UCompanionManager* Get();
    
    UFUNCTION(BlueprintCallable)
    static void DisableSystemicCompanionsForDungeons(const bool bDisable);
    
protected:
    UFUNCTION(BlueprintCallable)
    bool ChooseLocation(APawn* InCompanionPawn, FVector& OutDestination);
    
    UFUNCTION(BlueprintCallable)
    void ChangeCompanionInvulnerableBP(const FName& InCompanionName, const bool InBMakeInvulnerable);
    
    UFUNCTION(BlueprintCallable)
    bool CanSystemicallyCompanionable(const FName& InNPCName);
    
public:
    UFUNCTION(BlueprintCallable)
    static bool CanMoveCompanionBP(const APawn* Pawn, FCompanionFollowParams& Params);
    
    UFUNCTION(BlueprintCallable)
    void CancelAttackForAllCompanions();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanAddIdentity(const FName& InCompanionName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreSystemicCompanionsDisabled() const;
    
    UFUNCTION(BlueprintCallable)
    void AddIdentityToCompanion(const FName& InCompanionName, const FName& InIdentityName);
    
};

