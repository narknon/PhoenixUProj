#pragma once
#include "CoreMinimal.h"
#include "Able_Character.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ELinkType.h"
#include "OdcPathSpec.h"
#include "PathSpecInterface.h"
#include "Ambulatory_Character_Interface.h"
#include "CharacterTeleportedDelegate.h"
#include "EClimbingLadderState.h"
#include "EClimbingLedgeState.h"
#include "EJumpingType.h"
#include "ELandingType.h"
#include "EMobilityActionState.h"
#include "EMobilityModeState.h"
#include "ESpeedModifierType.h"
#include "ETargetSpeedMode.h"
#include "ETargetSpeedPriority.h"
#include "ValueTracker.h"
#include "Ambulatory_Character.generated.h"

class AActor;
class UAkAudioEvent;
class UAmbulatory_Data;
class UAnimInstance;
class UFootPlantEffects;
class UObject;
class UPrimitiveComponent;
class USceneComponent;
class USpeedModeTracker;
class UTargetTracker;

UCLASS(Blueprintable)
class AMBULATORY_API AAmbulatory_Character : public AAble_Character,/* public IAmbulatory_Character_Interface,*/ public IPathSpecInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* AkEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFootPlantEffects* FootPlantEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBiped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseTurnAssist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAbstractMobility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTestNewMobilityMotions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyLockOnMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumMovementSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumMovementSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlowWalkMovementSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WalkMovementSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FastWalkMovementSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float JogMovementSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SprintMovementSpeed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAmbulatory_Data* AmbulatoryData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcPathSpec PathSpec;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float JumpStartHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector JumpStartVelocity;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Debug;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* LadderActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FValueTracker WorldSpeedTracker;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterTeleported CharacterTeleportedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTargetTracker* LookAtTargetTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTargetTracker* FaceTargetTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTargetTracker* AimAtTargetTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpeedModeTracker* SpeedModeTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpeedModeTracker* SpeedModifierTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UPrimitiveComponent*> WadingWaterComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FixedWorldDirection;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> LedgeComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_navLinkUsingLedge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELinkType m_linkType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_traceWallRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_traceWallDropRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_traceWallForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_traceWallHeightAdjust;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_traceLedgeRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_traceLedgeIntoWallAdjust;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_traceLedgeUpAdjust;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_traceLedgeDownCast;
    
    AAmbulatory_Character();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StopWorldTurnInPlace();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StartWorldTurnInPlace(FVector WorldDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SprintStop();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SprintStart(ESpeedModifierType::Type SpeedModType);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ShowTimingMessage(const FString& MyMessage, UObject* WorldContextObject, float Duration);
    
    UFUNCTION(BlueprintCallable)
    void SetWorldSpeedAndDirection(float WorldSpeed, FVector WorldDirection);
    
    UFUNCTION(BlueprintCallable)
    void SetWorldSpeed(float WorldSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetUseSpeedModifier(bool bUseSpeedModifier);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetSpeedAndDirection(const float InAbstractSpeed, const FVector InDirection, bool InSetMobilityStateBasedOnSpeed);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetSpeed(float InAbstractSpeed, bool InSetMobilityStateBasedOnSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetSpeedMode(ETargetSpeedMode::Type SpeedMode, ETargetSpeedMode::Type SpeedModifier, ETargetSpeedPriority::Type SpeedPriority);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetMovementSpeeds(float InMin, float InMax);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetMountTransform(const FTransform& Transform);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetMountNormal(const FVector& Normal);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetMobilityModeState(EMobilityActionState::Type InMobilityModeState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetMobilityActionState(EMobilityActionState::Type InMobilityActionState, bool bSetTargetSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetLandingType(ELandingType::Type InType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetJumpingType(const TEnumAsByte<EJumpingType::Type>& InType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetIsInIdle(const bool isIdle);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetInWaterVolume(const bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetDesiredDirection(const FVector InWorldDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetClimbingLedgeState(EClimbingLedgeState::Type InType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetClimbingLadderState(EClimbingLadderState::Type InType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetBaseSpeedMode(ETargetSpeedMode::Type SpeedMode, ETargetSpeedMode::Type SpeedModifier);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_ForceTurnAndFace(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RevertSpeedMode(ETargetSpeedPriority::Type SpeedPriority);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RevertMobilityModeState();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RevertMobilityActionState(bool bSetTargetSpeed);
    
    UFUNCTION(BlueprintCallable)
    void RemoveWadingComponent(UPrimitiveComponent* InWaterComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void JumpStarted(UAnimInstance* InAnimInstance);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void JumpFinished(UAnimInstance* InAnimInstance);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWadingComponent(UPrimitiveComponent* InWaterComponent) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsUsingSpeedModifier();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetWadingComponentCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPrimitiveComponent* GetWadingComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetTargetSpeedModifier(TEnumAsByte<ETargetSpeedMode::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ESpeedModifierType::Type GetSpeedModifierType();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetPreviousMobilityActionState(TEnumAsByte<EMobilityActionState::Type>& OutMobilityActionState);
    
    UFUNCTION(BlueprintCallable)
    FOdcPathSpec GetPathSpec() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetMountTransform(FTransform& LedgeTransform);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetMountNormal(FVector& LedgeNormal);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetMobilityModeState(TEnumAsByte<EMobilityActionState::Type>& OutMobilityModeState);
    
    UFUNCTION(BlueprintCallable)
    void GetMobilityActionStateName(UAnimInstance* InAnimInstance, FString& OutString);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetMobilityActionState(TEnumAsByte<EMobilityActionState::Type>& OutMobilityActionState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UTargetTracker* GetLookAtTargetTracker();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    int32 GetLinkUsageFlags() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetLedgeTransform(FTransform& LedgeTransform);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetLedgeNormal(FVector& LedgeNormal);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetLandingType(TEnumAsByte<ELandingType::Type>& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetJumpingType(TEnumAsByte<EJumpingType::Type>& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetIsMovementInput();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetIsInIdle();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UTargetTracker* GetFaceTargetTracker();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetClimbingLedgeState(TEnumAsByte<EClimbingLedgeState::Type>& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetClimbingLadderState(TEnumAsByte<EClimbingLadderState::Type>& OutType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    int32 GetBlockageFlags() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetBaseSpeedMode(TEnumAsByte<ETargetSpeedMode::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UTargetTracker* GetAimAtTargetTracker();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DestroyAttachedSceneComponent(USceneComponent* InSceneComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float ComputeDesiredDirectionAngle(const FVector& InDirection, const bool bInComputeDegrees) const;
    
    UFUNCTION(BlueprintCallable)
    float ComputeAngleBetweenTargetTrackers(UTargetTracker* SourceTracker, UTargetTracker* DestTracker, const bool bInComputeDegrees);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float ComputeAngle(const FVector& InDirection, const FVector& InSourceForward, const bool bInComputeDegrees) const;
    
    UFUNCTION(BlueprintCallable)
    void CharacterRotatedBySupport(FRotator DeltaRotation);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    USceneComponent* AttachSceneComponent(FTransform InTransform, FName InTag);
    
    UFUNCTION(BlueprintCallable)
    void ApplySlideHorizontalMovement(float WorldSpeed, const FVector InWorldDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ApplyMobilityModeStateSpeeds(EMobilityModeState::Type InMobilityModeState);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AmIMovingIntoStairs() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AmIMovingIntoSlopes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AmIGoingUpStairs() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AmIGoingDownStairs() const;
    
    UFUNCTION(BlueprintCallable)
    void AddWadingComponent(UPrimitiveComponent* InWaterComponent);
    
    
    // Fix for true pure virtual functions not being implemented
};

