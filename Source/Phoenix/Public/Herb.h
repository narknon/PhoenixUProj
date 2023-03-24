#pragma once
#include "CoreMinimal.h"
#include "InteractiveObjectActor.h"
#include "Herb.generated.h"

class AHerbPlot;

UCLASS(Blueprintable)
class AHerb : public AInteractiveObjectActor {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 RespawnTime;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentStage;
    
public:
    AHerb(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    bool TryCreateBeacon();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyStageChange(int32 NewStage, bool bIsInitialState);
    
public:
    UFUNCTION(BlueprintCallable)
    bool IsMultiHarvestable();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInPlot() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFinalStage(int32 Stage) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AHerbPlot* GetPlot() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetPlantByproductID(FName PlantID);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetNumStages() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetHasInventorySpaceToHarvestPlantOfType(const FName PlantID, const FName CollectorCharacterID, const FName FertilizerID, bool bIsPlanted);
    
protected:
    UFUNCTION(BlueprintCallable)
    void FinishHarvestingHerb();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_NotifyHerbPlanted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_NotifyHerbHarvested();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_NotifyHerbDestroyed();
    
};

