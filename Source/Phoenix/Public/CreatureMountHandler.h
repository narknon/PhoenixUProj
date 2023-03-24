#pragma once
#include "CoreMinimal.h"
#include "SpawnSelectInfo.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "EHoverDroneControlMode.h"
#include "ClothMountTargets.h"
#include "CreatureMountSpawnLocationHandler.h"
#include "ECreatureMountErrorMessages.h"
#include "EMountTypes.h"
#include "MountCognitionSenseParams.h"
#include "NoMountZoneAvoidanceParams.h"
#include "Templates/SubclassOf.h"
#include "CreatureMountHandler.generated.h"

class ACharacter;
class AController;
class ACreatureMountTransitionActor;
class ACreature_Character;
class AMountedAI_Controller;
class UAblAbility;
class UCreature_MountComponent;
class UCreature_MountLandingDynamics;
class UCreature_RiderComponent;
class UInteractionArchitectAsset;
class UMaterialInstance;
class UMountHeightLimitComponent;
class UMountStreamingComponent;
class UMovementPredictionComponent;
class UPhysicsAsset;
class USkeletalMesh;

UCLASS(Blueprintable)
class ACreatureMountHandler : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnSelectInfo DbIdInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACreature_Character> CreatureClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* CreatureSkeletalMeshPreload;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstance*> CreatureMaterialsPreload;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MountedStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerMountAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> RiderPostDismountAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* ExistingCreatureInitialInteractionArchitectAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UMountStreamingComponent> MountStreamingComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UMountHeightLimitComponent> MountHeightLimitComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCreature_RiderComponent> CreatureRiderComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCreature_MountComponent> CreatureMountComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UMovementPredictionComponent> MovementPredictionComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMountedAI_Controller> MountedAIControllerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> CreatureMountVFXActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* MountedReactionsAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* MountedInteractionsAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ImmunityTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNoMountZoneAvoidanceParams NoMountZoneAvoidanceParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACreatureMountTransitionActor> MountTransitionActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MountTransitionActorAttachSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAdjustSpawnForCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreatureMountSpawnLocationHandler SpawnLocationHandler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMountTypes CreatureMountType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MountCapsuleName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhysicsAsset* CreaturePhysicAssetForRiderCloth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClothMountTargets ClothMountTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LevelScalingOverrideName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMountCognitionSenseParams MountCognitionParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMountCognitionSenseParams OriginalBipedCognitionParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroyHandlerAfterDismount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroyCreatureAfterDismount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACharacter* RiderCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACreature_Character* CreatureCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AController* RiderController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AController* PreviousCreatureController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AController* PreviousRiderController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACreatureMountTransitionActor* MountTransitionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChargeUnavailableMessageTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChargeOnCooldownMessageTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreature_MountLandingDynamics* FlightLandingDynamics;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ECreatureMountErrorMessages, FName> CreatureMountErrors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* CreatureMountVFXActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* PreviousMountReactionsAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* PreviousMountInteractionsAsset;
    
public:
    ACreatureMountHandler(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ToggleCreatureMountCapsule(ACreature_Character* InCreatureCharacter, const FName& InName, bool bInEnabled) const;
    
public:
    UFUNCTION(BlueprintCallable)
    void SpawnAndMountCreature(ACharacter* InRiderCharacter, bool bInUseTransition, bool bInInFlight);
    
    UFUNCTION(BlueprintCallable)
    void PlayerPossessRider();
    
    UFUNCTION(BlueprintCallable)
    void PlayerPossessCreature();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPostDismountCreature();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPostCreatureMountSpawn();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnHoverDroneControlModeChanged(EHoverDroneControlMode::Type NewMode);
    
public:
    UFUNCTION(BlueprintCallable)
    void MountExistingCreature(ACharacter* InRiderCharacter, ACreature_Character* InCreatureCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMountType(EMountTypes InType) const;
    
    UFUNCTION(BlueprintCallable)
    void DismountCreature(bool bInUseTransition);
    
};

