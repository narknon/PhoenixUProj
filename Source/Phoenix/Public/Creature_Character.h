#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "OdcFlags.h"
#include "CallOutAttachmentInterface.h"
#include "ECreatureAIInitialState.h"
#include "ECreatureCageAnimation.h"
#include "ECreatureFlightState.h"
#include "ECreatureLandingType.h"
#include "ECreatureMovementSpeed.h"
#include "ECreatureStoppingMode.h"
#include "FireInterface.h"
#include "NPC_Character.h"
#include "Creature_Character.generated.h"

class AActor;
class APathNode;
class UAkComponent;
class UAnimationComponent;
class UCentaurCombatComponent;
class UCreature_AIComponent;
class UCreature_CombatComponentV2;
class UCreature_FlightMotionTable;
class UCreature_MountComponent;
class UCreature_NurtureComponent;
class UEnemyStateComponent;
class UFlightAnimationComponent;
class UIcarus3DMovementComponent;
class UMercunaNavigationComponent;
class UParticleSystem;
class UUprightAttachSceneComponent;
class UUserWidget;

UCLASS(Blueprintable)
class PHOENIX_API ACreature_Character : public ANPC_Character, public IFireInterface, public ICallOutAttachmentInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationComponent* AnimationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyStateComponent* EnemyStateComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreature_FlightMotionTable* FlightMotionTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcFlags PreferredAreaUsageFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcFlags FleeAreaUsageFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer IgnoredSpellImpactTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRecordLastReceivedAnimNotify;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UUserWidget> FollowScreenWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureAIInitialState StartState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartTame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APathNode* StartPathNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Cage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureCageAnimation CageAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* SpawnVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnFlying;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnPerched;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AllowedColorVariationsOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideGender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsMaleOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RootMotionTranslationScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECreatureFlightState DesiredFlightState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECreatureLandingType DesiredLandingType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer DesiredTakeoffAnimationTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECreatureStoppingMode DesiredStoppingMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECreatureStoppingMode ActualStoppingMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECreatureMovementSpeed DesiredMovementSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCreature_AIComponent* CreatureAIComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCreature_NurtureComponent* NurtureComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCreature_CombatComponentV2* CombatComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UIcarus3DMovementComponent* FlightMovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMercunaNavigationComponent* FlightNavigationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFlightAnimationComponent* FlightAnimationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCentaurCombatComponent* CentaurCombatComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCreature_MountComponent* MountComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AnimationVariationTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<FName> LastReceivedAnimNotifyEventNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CalloutAttachmentSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform CalloutLocalOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AlertCalloutLocalOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTestForAudioOcclusion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxConcurrentAkComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxAkEventsPerFrame;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UUprightAttachSceneComponent* CreatedCalloutAttachComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAkComponent* OcclusionAkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAkComponent*> FootstepAkComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAkComponent* MotionAkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAkComponent*> VoxFoleyAkComponents;
    
public:
    ACreature_Character();
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool StartFire(float Amount, FVector Location);
    
    UFUNCTION(BlueprintCallable)
    void ShowCreatureFollowScreen();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetCanUseIdleBreaksDefaultValue(bool bValue);
    
    UFUNCTION(BlueprintCallable)
    bool SetAvoidanceAgainst(AActor* Actor, bool bEnable);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFireExtinguished();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCompletelyCharred();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActivePlayerMount() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetTrackerIsStationary();
    
    UFUNCTION(BlueprintCallable)
    float GetTrackerAverageSpeed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCreature_MountComponent* GetMountComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExecuteInitialIdleAbility();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExecuteInitialFlyingAbility();
    
    
    // Fix for true pure virtual functions not being implemented
};

