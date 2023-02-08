#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "EAdditiveBodyState.h"
#include "EAttackState.h"
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
#include "EParryState.h"
#include "EPartialBodyState.h"
#include "ERightArmPriority.h"
#include "ERightArmState.h"
#include "EStationState.h"
#include "InventoryResult.h"
#include "Biped_AnimInstance_Interface.generated.h"

class AActor;
class APickupTool;

UINTERFACE(Blueprintable, MinimalAPI)
class UBiped_AnimInstance_Interface : public UInterface {
    GENERATED_BODY()
};

class IBiped_AnimInstance_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetWandEquipped(bool WandEquipped);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetUseAimOffset(bool InUseAimOffset);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetStationState(const TEnumAsByte<EStationState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetRightArmState(ERightArmState::Type InState, ERightArmPriority::Type InPriority, bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetRelaxWand(const bool bInFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPickupTool(const APickupTool* InPickupTool);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPartialBodyState(const TEnumAsByte<EPartialBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetParryStateNext(const TEnumAsByte<EParryState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetParryState(const TEnumAsByte<EParryState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMobilityStateLast(const TEnumAsByte<EMobilityState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMobilityState(const TEnumAsByte<EMobilityState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetLeftArmState(ELeftArmState::Type InState, ELeftArmPriority::Type InPriority, bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIsHoldingAttack(bool InHoldingAttack);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetInventoryResult(const FInventoryResult InInventoryResult);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetHeadTrackingState(EHeadTrackingState::Type InState, EHeadTrackingPriority::Type InPriority, bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetHarvestState(const TEnumAsByte<EHarvestState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetFullBodyStateLast(const TEnumAsByte<EFullBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetFullBodyState(const TEnumAsByte<EFullBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetFireOnce(bool InFireOnce);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetDodgeState(const TEnumAsByte<EDodgeState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetCombatAdditiveState(ECombatAdditiveState::Type InState, ECombatAdditivePriority::Type InPriority, bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetChannelSpellFlourish(bool InFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetAttackState(const TEnumAsByte<EAttackState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetAmpedPercent(float InAmpedPercent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetAdditiveBodyState(const TEnumAsByte<EAdditiveBodyState::Type>& InState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetAbortAnim(bool InAbortAnim);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_DoFullBodySpellIfInIdle(bool bInDoFullBodySpellIfInIdle);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_AimOffsetYaw(const float& InYaw);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_AimOffsetPitch(const float& InPitch);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetStationState(TEnumAsByte<EStationState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    ERightArmState::Type GetRightArmState(ERightArmPriority::Type InPriority);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    APickupTool* GetPickupTool();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetPartialBodyState(TEnumAsByte<EPartialBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetParryStateNext(TEnumAsByte<EParryState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetParryState(TEnumAsByte<EParryState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetMobilityStateLast(TEnumAsByte<EMobilityState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetMobilityState(TEnumAsByte<EMobilityState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    ELeftArmState::Type GetLeftArmState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FInventoryResult GetInventoryResult();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    EHeadTrackingState::Type GetHeadTrackingState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetHarvestState(TEnumAsByte<EHarvestState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetFullBodyStateLast(TEnumAsByte<EFullBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetFullBodyState(TEnumAsByte<EFullBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetDodgeState(TEnumAsByte<EDodgeState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetAttackState(TEnumAsByte<EAttackState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetAdditiveBodyState(TEnumAsByte<EAdditiveBodyState::Type>& OutState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetAbortAnim() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_AimOffsetYaw(float& OutYaw);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_AimOffsetPitch(float& OutPitch);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ComputeAditiveReactDirection(AActor* InVictim, const FVector& InTraceDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ClearAttackState();
    
};

