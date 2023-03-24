#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ECreatureFeedingStationSlotVisualState.h"
#include "Templates/SubclassOf.h"
#include "TransfigurationObjectBase.h"
#include "CreatureFeedingStation.generated.h"

class ACreatureFeed;
class ACreature_Character;
class UAnimInstance;
class UCreatureFeedingStationState;
class USceneComponent;

UCLASS(Blueprintable)
class PHOENIX_API ACreatureFeedingStation : public ATransfigurationObjectBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FeedPelletsReleaseVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACreatureFeed> FeedActorClass;
    
    ACreatureFeedingStation(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UnregisterFeedingStationFromBiome();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UnhideFeed(UAnimInstance* FeederAnimInstance);
    
    UFUNCTION(BlueprintCallable)
    void Unassign(ACreature_Character* Creature);
    
    UFUNCTION(BlueprintCallable)
    void SetSlotVisualState(int32 SlotIdx, ECreatureFeedingStationSlotVisualState VisualState);
    
    UFUNCTION(BlueprintCallable)
    void RemoveOneFeed(int32 SlotIdx);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReleaseFeed(UAnimInstance* FeederAnimInstance);
    
    UFUNCTION(BlueprintCallable)
    void RegisterFeedingStationToBiome();
    
    UFUNCTION(BlueprintCallable)
    void RefillEmptyFeederSlots();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartedConverting();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFeedDispensed(ACreatureFeed* CreatureFeed, ACreature_Character* Creature);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFeedConverted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFeedAdded();
    
    UFUNCTION(BlueprintCallable)
    ECreatureFeedingStationSlotVisualState GetSlotVisualState(int32 SlotIdx);
    
    UFUNCTION(BlueprintCallable)
    UCreatureFeedingStationState* GetFeedingStationState();
    
    UFUNCTION(BlueprintCallable)
    FTransform GetBestSlotTransform(ACreature_Character* Creature);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FindSlotComponents(TArray<USceneComponent*>& OutSlotComponents);
    
    UFUNCTION(BlueprintCallable)
    bool DispenseFeed(ACreature_Character* Creature);
    
    UFUNCTION(BlueprintCallable)
    void ConvertAvailableFeederSlot();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_Init();
    
    UFUNCTION(BlueprintCallable)
    void AssignToSlot(ACreature_Character* Creature);
    
};

