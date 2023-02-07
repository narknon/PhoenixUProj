#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "Curves/CurveFloat.h"
#include "Mercuna3DMovementProperties.h"
#include "CreatureMountChargeAmountDelegate.h"
#include "CreatureMountChargeCooldownDelegate.h"
#include "CreatureMountChargeEnabledDelegate.h"
#include "CreatureMountChargeRefillDelayDelegate.h"
#include "CreatureMountChargeRequestDelegate.h"
#include "EMountCombatChargeState.h"
#include "EMountFlyingGait.h"
#include "EMountMovementState.h"
#include "MountMovementStateChangedDelegate.h"
#include "Templates/SubclassOf.h"
#include "Creature_MountComponent.generated.h"

class AActor;
class ACharacter;
class ACreatureMountHandler;
class ACreature_Character;
class UAblAbility;
class UAkAudioEvent;
class UCreature_MountFlightDynamics;
class UCreature_MountLandingDynamics;
class UFlightAnimationComponent;
class UIcarus3DMovementComponent;
class UMountHeightLimitComponent;
class UMountStreamingComponent;
class UMovementPredictionComponent;
class UTriggerEffect;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCreature_MountComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoverFlightGaitSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlowFlightGaitSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FastFlightGaitSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMountFlyingGait CurrentFlyingGait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMountCombatChargeState CurrentChargeState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CombatChargeActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CombatChargeEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatChargeRequestDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatChargeMinActiveDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatChargeCooldownDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatChargeRefillDelayDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatChargeRefillRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatChargeDepletionRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatChargeAmount_Max;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatChargeAmount_SpawnsWith;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatChargeAmount_MinUsable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatChargeWaterDepthLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* CombatChargeRunOutSfx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* CombatChargeNoChargeSfx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* CombatChargePreSpecialAttackSfx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DeactiveSfxTransitionDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthRefillDelayDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthRefillDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeathTimeout;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMountMovementStateChanged MovementStateChangedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACharacter* RiderCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCreature_MountLandingDynamics* LandingDynamics;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTriggerEffect* pChargeTriggerEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTriggerEffect* pJogTriggerEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeadZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TrotZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ButtonHoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ButtonTapTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToggleGallopTimeoutTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinInputTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StickBounceMagnitudeThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CameraRelativeAdjustmentAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve GallopHorizontalInputAdjustmentCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve GallopInputMagnitudeAdjustmentCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WallCollisionImpactAngleThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FlyingWallCollisionImpactAngleThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NoMountZoneCollisionImpactAngleThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreature_MountFlightDynamics* FlightDynamics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercuna3DMovementProperties FlyingMovementProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercuna3DMovementProperties LandingMovementProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> FlyingAdditiveAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FlyingAdditiveChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> TailAdditiveAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TailAdditiveChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D MaxLevelGlidingTimeRangeForSlowFlight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D MaxLevelGlidingTimeRangeForFastFlight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D MinGlidingResetTimeRangeForSlowFlight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D MinGlidingResetTimeRangeForFastFlight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxPitchForLevelFlight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinSpeedForLevelFlight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve PitchToMinGlideSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxPitchDegreesDownForFastFlightGait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinGlideSpeedForFastFlightGait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinFlightTimeForAutoLanding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpeedForTrotLanding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxInputMagnitudeForHover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDeltaYawToAccelerateWhenHovering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve FlightInputToPitchCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve DistanceToHeightLimitToMaxPitchMultiplierCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VerticalHoverCollisionPredictionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableAutoTakeoffWhenFalling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinFallingTimeForAutoTakeoff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinTimeToLandingForAutoTakeoff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoverGaitCapsuleHalfHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoverGaitCapsuleRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableIdleBreaks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinIdleTimeForIdleBreak;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinTimeBetweenIdleBreaks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveZ;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InputTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReleaseTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartedMoving;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsingKeyboard;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bToggleGallopRequested;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACreatureMountHandler* MountHandler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACreature_Character* OwnerCreatureCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UIcarus3DMovementComponent* FlightMovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFlightAnimationComponent* FlightAnimationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMountStreamingComponent* MountStreamingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMountHeightLimitComponent* MountHeightLimitComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMovementPredictionComponent* MovementPredictionComponent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreatureMountChargeEnabled CreatureMountChargeEnabledDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreatureMountChargeAmount CreatureMountChargeAmountDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreatureMountChargeRequest CreatureMountChargeRequestDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreatureMountChargeCooldown CreatureMountChargeCooldownDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreatureMountChargeRefillDelay CreatureMountChargeRefillDelayDelegate;
    
public:
    UCreature_MountComponent();
    UFUNCTION(BlueprintCallable)
    void UpdateMoveInput(float DeltaTime);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateGroundMovement(float DeltaTime);
    
public:
    UFUNCTION(BlueprintCallable)
    void ToggleGallopTimedOut();
    
    UFUNCTION(BlueprintCallable)
    void TakeoffRequested(bool bSkipTakeoffAnimation);
    
    UFUNCTION(BlueprintCallable)
    void TakeOffPressed();
    
protected:
    UFUNCTION(BlueprintCallable)
    void StopVocalSfx(int32 InTransitionDuration);
    
public:
    UFUNCTION(BlueprintCallable)
    void SpeedUpReleased();
    
    UFUNCTION(BlueprintCallable)
    void SpeedUpPressed(bool bSprintToggle);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowActionDiamond(bool bShow);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetMinimumFlyingGait(EMountFlyingGait InMinimumFlyingGait);
    
    UFUNCTION(BlueprintCallable)
    void SetAutoLandingEnabled(bool bInEnabled);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnNearDeathKneel(AActor* Owner);
    
    UFUNCTION(BlueprintCallable)
    void OnMovementModeChanged(ACharacter* Character, TEnumAsByte<EMovementMode> PrevMovementMode, uint8 PreviousCustomMode);
    
    UFUNCTION(BlueprintCallable)
    void OnHealthChanged(AActor* Target, float InHealthChange, bool bIndicateHUD);
    
public:
    UFUNCTION(BlueprintCallable)
    void LightAttackReleased();
    
    UFUNCTION(BlueprintCallable)
    void LightAttackPressed();
    
    UFUNCTION(BlueprintCallable)
    void LandingRequested();
    
    UFUNCTION(BlueprintCallable)
    void KeyboardWalkReleased();
    
    UFUNCTION(BlueprintCallable)
    void KeyboardWalkPressed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFlying() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EMountMovementState GetMovementState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<EMovementMode> GetMovementMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACreatureMountHandler* GetMountHandler() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetFlyingDistanceAboveGround(float& OutDistanceAboveGround) const;
    
    UFUNCTION(BlueprintCallable)
    void DismountTriggered();
    
    UFUNCTION(BlueprintCallable)
    void DismountReleased();
    
    UFUNCTION(BlueprintCallable)
    void DismountPressed();
    
    UFUNCTION(BlueprintCallable)
    void DismountBeganHold();
    
    UFUNCTION(BlueprintCallable)
    void DeactivateMountComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanFly() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanCharge() const;
    
    UFUNCTION(BlueprintCallable)
    void ActivateMountComponent(ACreatureMountHandler* InMountHandler, bool bInRiderIsPlayer);
    
};

