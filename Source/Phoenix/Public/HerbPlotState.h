#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "EHerbGrowthState.h"
#include "HerbPlotState.generated.h"

class AHerbPlot;

UCLASS(Blueprintable)
class UHerbPlotState : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AHerbPlot* HerbPlotActor;
    
public:
    UHerbPlotState();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGrowing() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetYield() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    float GetRegrowthTimeRatio() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetPlotID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetPlantID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsInSanctuary() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    FTimespan GetGrowthTimeRemaining() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EHerbGrowthState GetGrowthState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    float GetGrowthProgressRatio() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetFertilizerID() const;
    
};

