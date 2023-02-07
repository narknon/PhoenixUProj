#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "CreatureDefinition.generated.h"

UCLASS(Blueprintable)
class UCreatureDefinition : public UObject {
    GENERATED_BODY()
public:
    UCreatureDefinition();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOffspring() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEggLaying() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEgg() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAdult() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetTypeID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTimespan GetPregnancyDuration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetPreferredToyID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPlayWithToyHappinessPercentage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetOnlyCapturableWhenNearDeathKneeling() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetOffspringCreatureTypeID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumCapturingGates() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsCarnivore() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsAggressive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTimespan GetHatchingDuration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetEggTypeID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetConflictTypeIDs() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCompletedYearForCapture() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTimespan GetChildhoodDuration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCapturingTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCapturingDistanceMax() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCanBeCaptured() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetByproductID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetByproductHarvestCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetByproductCooldownTimeSec() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetBaseEconomyValue() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetAdultCreatureTypeID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetAchievementForCapturing() const;
    
};

