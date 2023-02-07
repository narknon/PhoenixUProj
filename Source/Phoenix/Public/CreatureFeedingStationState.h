#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EItemConversionState.h"
#include "CreatureFeedingStationState.generated.h"

UCLASS(Blueprintable)
class UCreatureFeedingStationState : public UObject {
    GENERATED_BODY()
public:
    UCreatureFeedingStationState();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasFeedAvailable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEmptySlot() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumFeedSlots() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EItemConversionState GetConversionState(int32 SlotIndex) const;
    
    UFUNCTION(BlueprintCallable)
    void FinalizeCurrentConversion();
    
};

