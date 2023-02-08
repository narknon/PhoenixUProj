#pragma once
#include "CoreMinimal.h"
#include "Able_AnimInstance.h"
#include "UObject/NoExportTypes.h"
#include "Ambulatory_AnimInstance_Interface.h"
#include "EAnimMechanicType.h"
#include "EAnimSpeedType.h"
#include "EClimbingLadderState.h"
#include "EClimbingLedgeState.h"
#include "EJumpingType.h"
#include "ELandingType.h"
#include "EMobilityActionState.h"
#include "EMobilityModeState.h"
#include "EPreWandCastState.h"
#include "EWandCastType.h"
#include "WandCastInfo.h"
#include "Ambulatory_AnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class AMBULATORY_API UAmbulatory_AnimInstance : public UAble_AnimInstance/*, public IAmbulatory_AnimInstance_Interface*/ {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMobilityModeState::Type> MobilityModeState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMobilityModeState::Type> PrevMobilityModeState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPartialBodyUseAbilitiesTest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMobilityActionState::Type> MobilityActionState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMobilityActionState::Type> PrevMobilityActionState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EJumpingType::Type> JumpType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ELandingType::Type> LandType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAnimSpeedType::Type> AnimSpeedType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAnimMechanicType::Type> AnimMechanicType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EClimbingLedgeState::Type> ClimbingLedgeState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EClimbingLadderState::Type> ClimbingLadderState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StrafeAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsMoving;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsAim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsMovementInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsTurningInPlace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsStrafing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DesiredIsStrafing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ForceTurnAndFace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool BlockedByWall;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsViewAlignedWithDesiredDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsActorAlignedWithDesiredDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LookAtDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DesiredDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpedDesiredDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastDesiredDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FixedDesiredDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StopTurnDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartTurnDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WalkRunLean;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Speed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FixedSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TrackingSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShortStepTrackingSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastDesiredWorldSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DesiredForwardBodyLean;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DesiredHorizontalBodyLean;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DesiredBodyTurn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GameTimeAtStartMove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GameTimeAtStopMove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimLeanYaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimLeanPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float JumpHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsFlicked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsOverridenForCinematic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsInIdle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LookAtTargetPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LookAtTargetYaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LookAtTargetLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HasLookAtTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ImpactDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsingStairsAnims;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWandCastInfo WandCastInfo;
    
    UAmbulatory_AnimInstance();
    UFUNCTION(BlueprintCallable)
    void WandCastInfo_ClearAttackCount();
    
    UFUNCTION(BlueprintCallable)
    void SetWandCastInfo_PreWandCastState(TEnumAsByte<EPreWandCastState::Type> PreWandCastState);
    
    UFUNCTION(BlueprintCallable)
    void SetWandCastInfo_AnticipationWandCastState(TEnumAsByte<EPreWandCastState::Type> AnticipationWandCastState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetStartMoveTimeToCurrentTime();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetPlayerIKState(bool State);
    
    UFUNCTION(BlueprintCallable)
    void SetNextWandCastType(TEnumAsByte<EWandCastType::Type> WandCastType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetLandingType(ELandingType::Type InType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetJumpingType(EJumpingType::Type InType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetIsViewAlignedWithDesiredDirection(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetIsAim(bool InIsAim);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetIsActorAlignedWithDesiredDirection(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetIKStateWithEaseIn(bool State, float Delay, float EaseTime);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetIKState(bool State);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetGlobalIKState(bool State);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetClimbingLedgeState(EClimbingLedgeState::Type InType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetClimbingLadderState(EClimbingLadderState::Type InType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_WandCastMelee(const bool bInFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_WalkRunLean(float InWalkRunLean);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_TrackingSpeed(float InSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_StopTurnDirection(float InDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_StartTurnDirection(float InDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_Speed(float InSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_ShortStepTrackingSpeed(float InSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_PlayRate(float InPlayRate);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_MobilityModeState(EMobilityModeState::Type InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_MobilityActionState(EMobilityActionState::Type InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_MaxSpeed(float InMaxSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_LookAtDirection(float InDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_LastDesiredWorldSpeed(float InSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_IsTurningInPlace(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_IsStrafing(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_IsOverridenForCinematic(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_IsMoving(bool InIsMoving);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_IsMovementInput(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_ForceTurnAndFace(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_FixedSpeed(float InSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_FixedDesiredDirection(float InDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_DesiredHorizontalBodyLean(float InDesiredHorizontalBodyLean);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_DesiredForwardBodyLean(float InDesiredForwardBodyLean);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_DesiredDirection(float InDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_DesiredBodyTurn(float InDesiredBodyTurn);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_AimLeanYaw(float InAimLeanYaw);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_AimLeanPitch(float InAimLeanPitch);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Revert_MobilityModeState();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Revert_MobilityActionState();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitRootMotionModifierVectors();
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EPreWandCastState::Type> GetWandCastInfo_AnticipationWandCastState();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetPlayerIKState();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetLandingType(TEnumAsByte<ELandingType::Type>& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetJumpingType(TEnumAsByte<EJumpingType::Type>& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetIKState();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetGlobalIKState();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetClimbingLedgeState(TEnumAsByte<EClimbingLedgeState::Type>& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetClimbingLadderState(TEnumAsByte<EClimbingLadderState::Type>& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool Get_WandCastMelee();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float Get_WalkRunLean();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_StopTurnDirection(float& OutDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_StartTurnDirection(float& OutDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_Speed(float& OutSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_PrevMobilityModeState(TEnumAsByte<EMobilityActionState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_PrevMobilityActionState(TEnumAsByte<EMobilityActionState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_PlayRate(float& OutPlayRate);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_MobilityModeState(TEnumAsByte<EMobilityActionState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_MobilityActionState(TEnumAsByte<EMobilityActionState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_MaxSpeed(float& OutMaxSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_LookAtDirection(float& OutDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_Lean(float& OutAimLeanYaw, float& OutAimLeanPitch);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_LastDesiredWorldSpeed(float& OutSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_IsTurningInPlace(bool& OutFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_IsMoving(bool& InIsMoving);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_IsMovementInput(bool& OutFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_FixedSpeed(float& OutSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_DesiredDirection(float& OutDirection);
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_TurnAssistOn();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_TurnAssistOff();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_StartMoveBegin();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_SetStrafing();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_MoveEnd();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_MoveBegin();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_LeftIdle();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_LandingFinished();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_JumpStarted();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_JumpFinished();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_IdleBegin();
    
    
    // Fix for true pure virtual functions not being implemented
};

