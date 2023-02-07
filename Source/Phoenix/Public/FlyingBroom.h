#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Pawn.h"
#include "Curves/CurveFloat.h"
#include "ECustomInterpType.h"
#include "EStandardManagedPriority.h"
#include "ClothMountTargets.h"
#include "EBroomDismountType.h"
#include "EBroomMountErrorMessages.h"
#include "EBroomMountType.h"
#include "EFlyingBroomHitObjectType.h"
#include "Templates/SubclassOf.h"
#include "FlyingBroom.generated.h"

class ABiped_Player;
class ABroomActionSpline;
class ACharacter;
class AEnemyBroomRider_AiController;
class AFlyingBroom;
class UAblAbility;
class UAkComponent;
class UAnimationArchitectAsset;
class UCapsuleComponent;
class UCurveFloat;
class UFlyingBroomAudio;
class UFlyingBroomMovementComponent;
class UFlyingBroomPhysics;
class UMountHeightLimitComponent;
class UMountStreamingComponent;
class UObject;
class UPhysicsAsset;
class UScheduledEntity;
class USkeletalMeshComponent;
class USplineComponent;
class UTriggerEffect;

UCLASS(Blueprintable)
class AFlyingBroom : public APawn {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EBroomMountErrorMessages, FName> BroomMountErrors;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APawn* MountedCharacter;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ABroomActionSpline> BroomActionSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LastDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActiveScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bScaleIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhysicsAsset* BroomPhysicAssetForRiderCloth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClothMountTargets ClothMountTargets;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* CapsuleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* BroomMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* BeaterMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFlyingBroomMovementComponent* MovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMountStreamingComponent* MountStreamingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMountHeightLimitComponent* MountHeightLimitComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* AudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerMountAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerDismountDiveAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerDismountGroundAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerDismountGround2JogAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PlayerDismountInstantAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> SwingBeaterAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> SwingBeaterBackhandAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> ThrowQuaffleAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> StudentHoverBroomFlyAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> StudentIdleAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAnimationArchitectAsset> BroomRiderAnims;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFlyingBroomAudio* FlyingBroomAudio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* DeadZoneCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeadZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FastFlightInputEaseSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve FastFlightInputMagnitudeAdjustmentCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GroundDismountHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinCollisionResponseSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IdleBreakTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedBoostUnavailableMessageTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECustomInterpType::Type> DecelerationInterpType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DecelerationInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTriggerEffect* pBoostTriggerEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTriggerEffect* pSpeedUpTriggerEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTriggerEffect* pInactiveTriggerEffect;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AEnemyBroomRider_AiController> MountedAIControllerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AEnemyBroomRider_AiController* EnemyAIController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFlyingBroomPhysics* StudentDefaultFlightData;
    
public:
    AFlyingBroom();
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void UpdateRTPCValue(float InRTPCValue, const FString& RTPC, FVector2D ValueRange, FVector2D AudioValueRange) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateBroomAudio(UFlyingBroomAudio* BroomAudio);
    
public:
    UFUNCTION(BlueprintCallable)
    bool Teleport(FVector DestLocation, float DestYaw, bool ResetCamera, bool TeleportPhysics);
    
    UFUNCTION(BlueprintCallable)
    void SupressHoverDisabledUI(const bool bDisable);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void StartSettingMaxFlyHeightValue(float Value, EStandardManagedPriority Priority, UObject* InInstigator) const;
    
    UFUNCTION(BlueprintCallable)
    void StartSettingForceHoverValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingDismountAllowedValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingDisableInputValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingDisableBarrelRollValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingBoostAllowedValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void ShowBroomHUD(bool bShow) const;
    
    UFUNCTION(BlueprintCallable)
    void SetupPlayerOnBroom(ABiped_Player* BipedPlayer);
    
    UFUNCTION(BlueprintCallable)
    void SetupBroomComponents(UCapsuleComponent* Capsule, UFlyingBroomMovementComponent* Movement, USkeletalMeshComponent* Mesh);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetSplineComponent(USplineComponent* InSplineComponent, const bool bTeleportToStart) const;
    
    UFUNCTION(BlueprintCallable)
    void SetScaleInfo(bool bInScaleIn, float InActiveScale);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetMaxFlyingSpeed(const float Speed) const;
    
    UFUNCTION(BlueprintCallable)
    void SetForceLand(const bool bInForceLand);
    
private:
    UFUNCTION(BlueprintCallable)
    void SafeDismountHeightCheck();
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveRiderClothCollisionSources(const ACharacter* Character, bool bRemoveDelegates);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void PushFlightDataOntoStack(UFlyingBroomPhysics* NewFlightData) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void PopFlightDataOffStack() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTurboStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayerMountBroom();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayerDismountBroom();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNPCMountBroom();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNPCDismountBroom();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnMountedNPCHiddenIsChanged(UScheduledEntity* inParticipant, bool inHidden);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLeaveBoostZone();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnterBoostZone();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBoostStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBarrelRollStart(bool bRollLeft);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnActorIsHiddenChanged(bool NewValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInTurbo() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInHoverMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInBoost() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsForceLanding() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBoostRecharging() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxBoostMeter();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<EFlyingBroomHitObjectType> GetLastHitObject() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<EBroomDismountType> GetDismountType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBoostMeterAmount();
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void FinishSettingMaxFlyHeightValue(EStandardManagedPriority Priority, UObject* InInstigator) const;
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingForceHoverValue(EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingDismountAllowedValue(EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingDisableInputValue(EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingDisableBarrelRollValue(EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingBoostAllowedValue(EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void EnableMovement() const;
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void EnableMountedRiderIKSetup(bool bEnabled) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DismountBroom(ABiped_Player* Player, bool Instant);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DisableSpellHUD(bool NewDisableSpellHUD, bool DisableHealtHUD);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void DisableMovement() const;
    
    UFUNCTION(BlueprintCallable)
    void DetachPlayerFromBroomOnDismount(ABiped_Player* BipedPlayer, AFlyingBroom* BroomProp, float VelocityDamping);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanIdleBreak() const;
    
    UFUNCTION(BlueprintCallable)
    void BroomEvent(FName EventName);
    
    UFUNCTION(BlueprintCallable)
    void AttachPlayerToBroomOnMount(ABiped_Player* BipedPlayer, AFlyingBroom* BroomProp, TEnumAsByte<EBroomMountType> InMountType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ApplyBroomStats();
    
    UFUNCTION(BlueprintCallable)
    bool AllowDismount();
    
    UFUNCTION(BlueprintCallable)
    void AIMountBroom(ACharacter* Character, UFlyingBroomPhysics* FlightData);
    
    UFUNCTION(BlueprintCallable)
    void AIDismountBroom();
    
    UFUNCTION(BlueprintCallable)
    void AddRiderClothCollisionSources(const ACharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    void AddBoostPercentage(float Percent);
    
    UFUNCTION(BlueprintCallable)
    void AcceleratePressed();
    
};

