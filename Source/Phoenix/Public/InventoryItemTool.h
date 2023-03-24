#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Name_GameLogicVarBool.h"
#include "SelectableName.h"
#include "Tool.h"
#include "EHeadTrackingState.h"
#include "ELeftArmState.h"
#include "ERightArmState.h"
#include "InventoryResult.h"
#include "ItemProperties.h"
#include "Templates/SubclassOf.h"
#include "InventoryItemTool.generated.h"

class AActor;
class ACharacter;
class AMunitionType_Base;
class UInventoryItemToolRecord;

UCLASS(Blueprintable)
class PHOENIX_API AInventoryItemTool : public ATool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryResult InventoryResult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemProperties ItemProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTriggerAbilityOnConsume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSelectableName CustomAbilityName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* UseItemAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* EquipItemAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* HoldItemAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* HandOnlyItemAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ELeftArmState::Type> LeftArmState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ERightArmState::Type> RightArmState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EHeadTrackingState::Type> HeadTrackingState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableRiderHandIK;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinUsageTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxUsageTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UnEquipTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartUnequipTimerOnConsume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowUseWhenCountIsZero;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoresTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideWhenDepleted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicVarBool ContextToSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseItemOnEndSelection;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasCustomAnimation;
    
public:
    AInventoryItemTool(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UseItem();
    
protected:
    UFUNCTION(BlueprintCallable)
    void UnequipTool();
    
public:
    UFUNCTION(BlueprintCallable)
    void TimeOutTimerExpired();
    
protected:
    UFUNCTION(BlueprintCallable)
    void StartUnequipTimer();
    
public:
    UFUNCTION(BlueprintCallable)
    AMunitionType_Base* SpawnMunition(TSubclassOf<AMunitionType_Base> MunitionClass, FVector SourceLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SpawnInventoryObject(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void SetSpeedBasedOnDistance(AMunitionType_Base* Munition, float Time, float MinSpeed, float MaxSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnItemConsumed();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnHidden(bool bFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDeactivate();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCustomAnimation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnActivate();
    
    UFUNCTION(BlueprintCallable)
    bool ItemHasCustomAnimation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ItemEvent(FName EventName);
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<ELeftArmState::Type> GetLeftArmState(FName Mechanic);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryItemToolRecord* GetInventoryItemToolRecord() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter* GetCharacter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FullBodyItemUsageCompleted();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void EndItemUsage();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void EndItemSelection();
    
    UFUNCTION(BlueprintCallable)
    bool ConsumeItem();
    
    UFUNCTION(BlueprintCallable)
    FVector ComputeVelocityToTarget(AActor* ProjectileActor, float Time, float MinSpeed, float MaxSpeed);
    
protected:
    UFUNCTION(BlueprintCallable)
    void CancelUnequipTimer();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void BeginItemUsage();
    
};

