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
#include "ESpeedModifierType.h"
#include "ETargetSpeedMode.h"
#include "ETargetSpeedPriority.h"
#include "Ambulatory_Character_Interface.generated.h"

class UAnimInstance;
class USceneComponent;
class UTargetTracker;

UINTERFACE(Blueprintable, MinimalAPI)
class UAmbulatory_Character_Interface : public UInterface {
    GENERATED_BODY()
};

class IAmbulatory_Character_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StopWorldTurnInPlace();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartWorldTurnInPlace(const FVector WorldDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SprintStop();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SprintStart(ESpeedModifierType::Type SpeedModType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetUseSpeedModifier(bool bUseSpeedModifier);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTurnAssist(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetSpeedMode(ETargetSpeedMode::Type SpeedMode, ETargetSpeedMode::Type SpeedModifier, TEnumAsByte<ETargetSpeedPriority::Type> SpeedPriority);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMovementSpeeds(float InMin, float InMax);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMountTransform(const FTransform& Transform);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMountNormal(const FVector& Normal);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMobilityModeState(EMobilityModeState::Type InMobilityModeState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMobilityActionState(EMobilityActionState::Type InMobilityActionState, bool bSetTargetSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetLandingType(TEnumAsByte<ELandingType::Type> InType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetJumpingType(TEnumAsByte<EJumpingType::Type> InType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIsInIdle(const bool IsInIdle);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetInWaterVolume(bool bInFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetDesiredDirection(const FVector InWorldDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetClimbingLedgeState(EClimbingLedgeState::Type InType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetClimbingLadderState(EClimbingLadderState::Type InType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetBaseSpeedMode(ETargetSpeedMode::Type SpeedMode, ETargetSpeedMode::Type SpeedModifier);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_ForceTurnAndFace(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RevertSpeedMode(TEnumAsByte<ETargetSpeedPriority::Type> SpeedPriority);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RevertMobilityModeState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RevertMobilityActionState(bool bSetTargetSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void JumpStarted(UAnimInstance* InAnimInstance);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void JumpFinished(UAnimInstance* InAnimInstance);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool IsUsingSpeedModifier();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetTargetSpeedModifier(ETargetSpeedMode::Type& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TEnumAsByte<ESpeedModifierType::Type> GetSpeedModifierType();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetPreviousMobilityActionState(EMobilityActionState::Type& OutMobilityActionState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetMountTransform(FTransform& LedgeTransform);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetMountNormal(FVector& LedgeNormal);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetMobilityModeState(EMobilityActionState::Type& OutMobilityModeState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetMobilityActionState(EMobilityActionState::Type& OutMobilityActionState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UTargetTracker* GetLookAtTargetTracker();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetLedgeTransform(FTransform& OutTransform);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetLedgeNormal(FVector& OutVector);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetLandingType(TEnumAsByte<ELandingType::Type>& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetJumpingType(TEnumAsByte<EJumpingType::Type>& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetIsMovementInput();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetIsInIdle();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UTargetTracker* GetFaceTargetTracker();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetClimbingLedgeState(EClimbingLedgeState::Type& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetClimbingLadderState(EClimbingLadderState::Type& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetBaseSpeedMode(ETargetSpeedMode::Type& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UTargetTracker* GetAimAtTargetTracker();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DestroyAttachedSceneComponent(USceneComponent* InSceneComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    USceneComponent* AttachSceneComponent(FTransform InTransform, FName InTag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ApplyMobilityModeStateSpeeds(EMobilityActionState::Type InMobilityModeState);
    
};
*/

