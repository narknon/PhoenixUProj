#pragma once
#include "CoreMinimal.h"
#include "EHerbGrowthState.h"
#include "InteractiveObjectActor.h"
#include "HerbPlot.generated.h"

class AHerb;
class AHerbPlot;
class UAkAudioEvent;
class UChildActorComponent;
class UHerbPlotState;

UCLASS(Blueprintable)
class AHerbPlot : public AInteractiveObjectActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHerbPlotBecomeInactiveDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHerbPlotBecomeActiveDelegate);
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHerbPlotBecomeActiveDelegate HerbPlotBecomeActiveDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHerbPlotBecomeInactiveDelegate HerbPlotBecomeInactiveDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* PotionedSFXEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* FertilizedSFXEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* PlantedSFXEvent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AHerbPlot* LeftNeighbor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AHerbPlot* RightNeighbor;
    
public:
    AHerbPlot(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    static void SetPlotNeighborsFromChildComponents(const TArray<UChildActorComponent*>& ChildComponents, bool bLoopNeighbors);
    
    UFUNCTION(BlueprintCallable)
    void PlantSeed(FName PlantID, FName InteractorID);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OpenPlotUI();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyInitialize();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyHerbPlanted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyHerbDestroyed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyHarvested(bool bIsMultiHarvest);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyGrowAfterInitialize();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyFertilized(bool IsFertilized, const FName FertilizerID, bool IsInitialState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyCompleteGrowth();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyBeginGrowth();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInLineWithNeighbors() const;
    
    UFUNCTION(BlueprintCallable)
    void HarvestHerb(FName CollectorCharacterID);
    
    UFUNCTION(BlueprintCallable)
    UHerbPlotState* GetPlotState();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AHerb* GetPlantedHerb() const;
    
    UFUNCTION(BlueprintCallable)
    void ForceState(const FName PlantID, const FName FertilizerID, const EHerbGrowthState GrowthState, const float GrowthProgress);
    
    UFUNCTION(BlueprintCallable)
    void ForceGrowthState(const EHerbGrowthState GrowthState, const float GrowthProgress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EnableCustomCamera();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DisableCustomCamera();
    
    UFUNCTION(BlueprintCallable)
    void DestroyHerb();
    
    UFUNCTION(BlueprintCallable)
    void ApplyFertilizer(FName FertilizerID, FName InteractorID);
    
};

