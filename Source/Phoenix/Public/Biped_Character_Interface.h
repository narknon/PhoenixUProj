/*
#pragma once
#include "CoreMinimal.h"
#include "EClimbingLedgeState.h"
#include "EJumpingType.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/PlayerController.h"
#include "Name_GameLogicVarInt32.h"
#include "ECustomInterpType.h"
#include "EAdditiveBodyState.h"
#include "EFullBodyState.h"
#include "EParryState.h"
#include "EPartialBodyState.h"
#include "EReactionState.h"
#include "ERightArmPriority.h"
#include "ERightArmState.h"
#include "InventoryResult.h"
#include "Templates/SubclassOf.h"
#include "Biped_Character_Interface.generated.h"

class ABiped_Character;
class AActor;
class APawn;
class APickupTool;
class AWandTool;
class UCurveFloat;
class UPrimitiveComponent;
class USkeletalMeshComponent;
class UStickFlickWatcherRecord;

UINTERFACE(Blueprintable, MinimalAPI)
class UBiped_Character_Interface : public UInterface {
    GENERATED_BODY()
};

class IBiped_Character_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UseInventoryItemByName(FName InventoryObjectID);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UnLockOnToActor();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UnEquipWand();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StopMove();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    APawn* SpawnStudent(TSubclassOf<ABiped_Character> StudentClass);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    AActor* SpawnLookAtTarget(TSubclassOf<AActor> SpawnActorClass);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    AActor* SpawnFaceTarget(TSubclassOf<AActor> SpawnActorClass);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetSpellCastHandle(int32 InSpellCastHandle);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetRootMotionOffsets(const FVector& TranslationOffset, const FRotator& RotationOffset);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetRootMotionOffset();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetRightArmState(ERightArmState::Type InState, ERightArmPriority::Type InPriority, bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPickupTool(const APickupTool* InPickupTool);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPhoenixCameraRotation(const FRotator& DesiredRotation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPhoenixCameraLookAt_TimeBased(const FVector& LookAtPoint, float LookAtTime);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPhoenixCameraLookAt_ActorAndTime(AActor* LookAtActor, float LookAtTime);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPhoenixCameraLookAt_Actor(AActor* LookAtActor, float ScaleSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPhoenixCameraLookAt(const FVector& LookAtPoint, float ScaleSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPartialBodyState(const TEnumAsByte<EPartialBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetParryState(const TEnumAsByte<EParryState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetFullBodyStateLast(const TEnumAsByte<EFullBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetFullBodyState(const TEnumAsByte<EFullBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetFinisherOptimalRatio(const float OptimalRatio, EDynamicForceFeedbackAction::Type FeedbackAction);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetAdditiveBodyState(const TEnumAsByte<EAdditiveBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ResetPhoenixCameraRotation(float ResetSpeed, UCurveFloat* ResetSpeedCurve);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RequestStick(float StickX, float StickY);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RequestMove(float StickX, float StickY, const float DeltaTime, float& Speed, float& Direction, float& LookAtDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReleasePhoenixCameraLookAt();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReadyModeStop();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReadyModeStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool QuickActionInteract();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PushDisableStack(FName_GameLogicVarInt32 StackName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool ProcessStick(float StickX, float StickY, const float DeltaTime, const UCurveFloat* DeadZoneCurve, const UCurveFloat* SpeedCurve, const UCurveFloat* SpeedGovernorCurve, float& WorldSpeed, FVector& WorldDirection, ECustomInterpType::Type InterpType, float InterpSpeed, float StickMagReductionDelayTimer);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PopDisableStack(FName_GameLogicVarInt32 StackName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PauseMenuStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FName ParkourJump(FName DefaultNode);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void LockOnToActor(AActor* InLockOnActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void LockOnCamFlick(UStickFlickWatcherRecord* InStickFlickWatcherRecord);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void LockOnCameraMoving(bool bFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool IsInReadyMode();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool IsDead();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool InstaUseInventoryItem();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool InLockOnMode();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    AWandTool* GetWand() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetToTargetDirection();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetTargetDirection();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetTargetDestination() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UPrimitiveComponent* GetTargetComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FName GetTargetBoneName();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetSpellCastHandle(int32& OutSpellCastHandle);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UCurveFloat* GetSpeedGovernorCurve();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UCurveFloat* GetSpeedCurve(bool& bIgnoreGovernor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    USkeletalMeshComponent* GetSkeletalMesh() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetRootMotionOffset(FVector& OutTranslationOffset);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    ERightArmState::Type GetRightArmState(ERightArmPriority::Type InPriority);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float GetPutdownToolHeight();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float GetPickupToolHeight();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    APickupTool* GetPickupTool();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetPartialBodyState(TEnumAsByte<EPartialBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetParryState(TEnumAsByte<EParryState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FInventoryResult GetInventoryResult();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    AActor* GetHighlitActor();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetFullBodyStateLast(TEnumAsByte<EFullBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetFullBodyState(TEnumAsByte<EFullBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector GetBestLockOnActor_WorldLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector GetBestLockOnActor_ScreenLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    AActor* GetBestLockOnActor();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector GetBestAutoTargetActor_WorldLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    AActor* GetBestAutoTargetActor();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetAutoTargetUpDirection();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetAutoTargetFocusDirection();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetAdditiveBodyState(TEnumAsByte<EAdditiveBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FullyResetPhoenixCamera(float ResetSpeed, UCurveFloat* ResetSpeedCurve);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FlooStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EquipWand();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ComputeReaction(FVector HitLocation, FVector TraceDirection, const FString& OverrideName, TEnumAsByte<EReactionState::Type>& ReactionState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ComputeAttack(AActor*& TargetActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float ComputeAngleToDesiredDirection();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ClearStick();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector CalculateLookAtDirection();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CalculateClimbingLedgeState(EClimbingLedgeState::Type& OutState, TEnumAsByte<EJumpingType::Type>& OutType);
    
};
*/

