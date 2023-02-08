/*
#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EClimbingLadderState.h"
#include "EClimbingLedgeState.h"
#include "EJumpingType.h"
#include "ELandingType.h"
#include "EMobilityActionState.h"
#include "EMobilityModeState.h"
#include "Ambulatory_AnimInstance_Interface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UAmbulatory_AnimInstance_Interface : public UInterface {
    GENERATED_BODY()
};

class IAmbulatory_AnimInstance_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetStartMoveTimeToCurrentTime();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetRootMotionOffsets(const FVector& TranslationOffset, const FRotator& RotationOffset);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPlayerIKState(bool State);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetLandingType(ELandingType::Type InType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetJumpingType(EJumpingType::Type InType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIsViewAlignedWithDesiredDirection(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIsAim(bool InIsAim);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIsActorAlignedWithDesiredDirection(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIKState(bool State);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetGlobalIKState(bool State);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetClimbingLedgeState(EClimbingLedgeState::Type InType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetClimbingLadderState(EClimbingLadderState::Type InType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_WandCastMelee(const bool bInFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_WalkRunLean(float InWalkRunLean);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_TrackingSpeed(float InSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_StopTurnDirection(float InDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_StartTurnDirection(float InDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_Speed(float InSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_ShortStepTrackingSpeed(float InSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_PlayRate(float InPlayRate);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_MobilityModeState(EMobilityModeState::Type InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_MobilityActionState(EMobilityActionState::Type InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_MaxSpeed(float InMaxSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_LookAtDirection(float InDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_LastDesiredWorldSpeed(float InSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_IsTurningInPlace(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_IsStrafing(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_IsOverridenForCinematic(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_IsMoving(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_IsMovementInput(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_ForceTurnAndFace(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_FixedSpeed(float InSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_FixedDesiredDirection(float InDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_DesiredHorizontalBodyLean(float InDesiredHorizontalBodyLean);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_DesiredForwardBodyLean(float InDesiredForwardBodyLean);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_DesiredDirection(float InDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_DesiredBodyTurn(float InDesiredBodyTurn);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_AimLeanYaw(float InAimLeanYaw);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_AimLeanPitch(float InAimLeanPitch);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Revert_MobilityModeState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Revert_MobilityActionState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InitRootMotionModifierVectors();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetPlayerIKState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetLandingType(TEnumAsByte<ELandingType::Type>& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetJumpingType(TEnumAsByte<EJumpingType::Type>& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetIKState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetGlobalIKState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetClimbingLedgeState(EClimbingLedgeState::Type& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetClimbingLadderState(EClimbingLadderState::Type& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool Get_WandCastMelee();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float Get_WalkRunLean();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_StopTurnDirection(float& OutDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_StartTurnDirection(float& OutDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_Speed(float& OutSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_PrevMobilityModeState(EMobilityActionState::Type& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_PrevMobilityActionState(EMobilityActionState::Type& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_PlayRate(float& OutPlayRate);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_MobilityModeState(EMobilityActionState::Type& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_MobilityActionState(EMobilityActionState::Type& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_MaxSpeed(float& OutMaxSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_LookAtDirection(float& OutDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_Lean(float& OutAimLeanYaw, float& OutAimLeanPitch);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_LastDesiredWorldSpeed(float& OutSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_IsTurningInPlace(bool& OutFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_IsMoving(bool& OutFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_IsMovementInput(bool& OutFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_FixedSpeed(float& OutSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_FixedDesiredDirection(float& OutDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_DesiredDirection(float& OutDirection);
    
};
*/

