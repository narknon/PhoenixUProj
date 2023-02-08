#pragma once
#include "CoreMinimal.h"
#include "Ambulatory_AnimInstance.h"
#include "UObject/NoExportTypes.h"
#include "TargetedByMunition.h"
#include "Biped_AnimInstance_Interface.h"
#include "CombatAdditiveStateChangedDelegateDelegate.h"
#include "EAdditiveBodyState.h"
#include "EAttackState.h"
#include "EBasicMobilityMode.h"
#include "ECombatAdditivePriority.h"
#include "ECombatAdditiveState.h"
#include "EDodgeState.h"
#include "EFullBodyState.h"
#include "EHarvestState.h"
#include "EHeadTrackingPriority.h"
#include "EHeadTrackingState.h"
#include "ELeftArmPriority.h"
#include "ELeftArmState.h"
#include "EMobilityState.h"
#include "EOpenDoorAnimState.h"
#include "EParryState.h"
#include "EPartialBodyState.h"
#include "ERightArmPriority.h"
#include "ERightArmState.h"
#include "ESBlockedByWallAnimState.h"
#include "EStationMode.h"
#include "EStationState.h"
#include "Enemy_ParryTimeToImpactData.h"
#include "InventoryResult.h"
#include "LeftArmStateChangedDelegateDelegate.h"
#include "RightArmStateChangedDelegateDelegate.h"
#include "Biped_AnimInstance.generated.h"

class AActor;
class APickupTool;

UCLASS(Blueprintable, NonTransient)
class UBiped_AnimInstance : public UAmbulatory_AnimInstance, public IBiped_AnimInstance_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ESBlockedByWallAnimState::Type> BlockedByWallState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EOpenDoorAnimState::Type> OpenDoorState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAttackState::Type> AttackState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EParryState::Type> ParryState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EParryState::Type> ParryStateNext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EDodgeState::Type> DodgeState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EStationState::Type> StationState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EStationMode::Type> StationMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EFullBodyState::Type> FullBodyState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EFullBodyState::Type> FullBodyStateLast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMobilityState::Type> MobilityTypeState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMobilityState::Type> MobilityTypeStateLast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EHarvestState::Type> HarvestState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EPartialBodyState::Type> PartialBodyState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TEnumAsByte<ELeftArmPriority::Type>, TEnumAsByte<ELeftArmState::Type>> LeftArmStateMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TEnumAsByte<ERightArmPriority::Type>, TEnumAsByte<ERightArmState::Type>> RightArmStateMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LeftArmActiveCinematicCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RightArmActiveCinematicCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TEnumAsByte<EHeadTrackingPriority::Type>, TEnumAsByte<EHeadTrackingState::Type>> HeadTrackingStateMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TEnumAsByte<ECombatAdditivePriority::Type>, TEnumAsByte<ECombatAdditiveState::Type>> CombatAdditiveStateMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAdditiveBodyState::Type> AdditiveBodyState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* CombatAdditiveAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsInAir;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsCrouching;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InLockOnMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AmpedPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialJumpAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APickupTool* PickupTool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PickupToolHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PutdownToolHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HoldingBucket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsMultiHarvestPlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 UseAimOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimOffsetYaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimOffsetPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastAimOffsetYaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsEquippingWand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsWandEquipped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DoFullBodySpellIfInIdle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsWandReady;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAdditiveTurnLeanActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdditiveLeanAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryResult InventoryResult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FlooName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsFlooUIFinished;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsFlooUICancelled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsAdvanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LoadFinished;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TeleportFinished;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool BackAwayFromLedge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlayBlockedByWallAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator LeftFootRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator RightFootRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftEffectorLoc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightEffectorLoc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LeftJointLoc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector RightJointLoc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HipsOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector GroundAcceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D AdditiveReact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_ParryTimeToImpactData ParryImpactData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTargetedByMunition ProtegoTargetedByMuntion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsHoldingAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsAbortingParry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsAbortingAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsAnticipatingAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnticipationAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThrowDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AngleToDesiredDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFromLightDirectional;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IdleTimeStamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CustomRootMotionMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLeftArmStateChangedDelegate LeftArmStateChangedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRightArmStateChangedDelegate RightArmStateChangedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCombatAdditiveStateChangedDelegate CombatAdditiveStateChangedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> AttackingActorStack;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> CurrentAttackingActor;
    
    UBiped_AnimInstance();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StartSettingCinematicRightArmState(ERightArmState::Type InState, bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StartSettingCinematicLeftArmState(ELeftArmState::Type InState, bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetWandEquipped(bool WandEquipped);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetUseAimOffset(bool InUseAimOffset);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetStationState(const TEnumAsByte<EStationState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetStationMode(const TEnumAsByte<EStationMode::Type>& InMode);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetRightArmState(ERightArmState::Type InState, ERightArmPriority::Type InPriority, bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetPickupTool(APickupTool* InPickupTool);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetPartialBodyState(const TEnumAsByte<EPartialBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetParryStateNext(const TEnumAsByte<EParryState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetParryState(const TEnumAsByte<EParryState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetMobilityStateLast(const TEnumAsByte<EMobilityState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetMobilityState(const TEnumAsByte<EMobilityState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetLeftArmState(ELeftArmState::Type InState, ELeftArmPriority::Type InPriority, bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetIsHoldingAttack(bool InHoldingAttack);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetInventoryResult(const FInventoryResult InInventoryResult);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetHeadTrackingState(EHeadTrackingState::Type InState, EHeadTrackingPriority::Type InPriority, bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetHarvestState(const TEnumAsByte<EHarvestState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetFullBodyStateLast(const TEnumAsByte<EFullBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetFullBodyState(const TEnumAsByte<EFullBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetDodgeState(const TEnumAsByte<EDodgeState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetCombatAdditiveState(ECombatAdditiveState::Type InState, ECombatAdditivePriority::Type InPriority, bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetAttackState(const TEnumAsByte<EAttackState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetAmpedPercent(float InAmpedPercent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetAdditiveBodyState(const TEnumAsByte<EAdditiveBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetAbortAnim(bool InAbortAnim);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_DoFullBodySpellIfInIdle(bool bInDoFullBodySpellIfInIdle);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_AimOffsetYaw(const float& InYaw);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Set_AimOffsetPitch(const float& InPitch);
    
    UFUNCTION(BlueprintCallable)
    void PushNewBasicMobilityMode(const int32 UniqueIDOverride, int32& UniqueId, TEnumAsByte<EBasicMobilityMode::Type> Mode);
    
    UFUNCTION(BlueprintCallable)
    void PopBasicMobilityMode(int32 UniqueId);
    
    UFUNCTION(BlueprintCallable)
    void OnLeftArmStateChanged(TEnumAsByte<ELeftArmState::Type> InLeftArmState);
    
    UFUNCTION(BlueprintCallable)
    void OnCombatAdditiveStateChanged(TEnumAsByte<ECombatAdditiveState::Type> InCombatAdditiveState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetStationState(TEnumAsByte<EStationState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetStationMode(TEnumAsByte<EStationMode::Type>& OutMode);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ERightArmState::Type GetRightArmState(ERightArmPriority::Type InPriority);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    APickupTool* GetPickupTool();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetPartialBodyState(TEnumAsByte<EPartialBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetParryStateNext(TEnumAsByte<EParryState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetParryState(TEnumAsByte<EParryState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable)
    int32 GetNumberOfAttackingActors();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetMobilityStateLast(TEnumAsByte<EMobilityState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetMobilityState(TEnumAsByte<EMobilityState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ELeftArmState::Type GetLeftArmState();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FInventoryResult GetInventoryResult();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    EHeadTrackingState::Type GetHeadTrackingState();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetHarvestState(TEnumAsByte<EHarvestState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetFullBodyStateLast(TEnumAsByte<EFullBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetFullBodyState(TEnumAsByte<EFullBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable)
    AActor* GetFirstAttackingActorInStack();
    
    UFUNCTION(BlueprintCallable)
    AActor* GetFirstAttackingActor();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetDodgeState(TEnumAsByte<EDodgeState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EBasicMobilityMode::Type> GetDefaultBasicMobilityMode();
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EBasicMobilityMode::Type> GetCurrentBasicMobilityMode();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetAttackState(TEnumAsByte<EAttackState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetAdditiveBodyState(TEnumAsByte<EAdditiveBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool GetAbortAnim() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_AimOffsetYaw(float& OutYaw);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Get_AimOffsetPitch(float& OutPitch);
    
    UFUNCTION(BlueprintCallable)
    void FullyResetBasicMobilityMode();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FinishSettingCinematicRightArmState(bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FinishSettingCinematicLeftArmState(bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ComputeAditiveReactDirection(AActor* InVictim, const FVector& InTraceDirection);
    
    
    // Fix for true pure virtual functions not being implemented
};

