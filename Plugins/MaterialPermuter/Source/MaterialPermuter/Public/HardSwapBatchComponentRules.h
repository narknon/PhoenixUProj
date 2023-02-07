#pragma once
#include "CoreMinimal.h"
#include "HardSwapBatchComponent.h"
#include "HardSwapBatchComponentSettings.h"
#include "MaterialPermuterHardSwapRules.h"
#include "HardSwapBatchComponentRules.generated.h"

class AActor;
class UHardSwapBatchComponentRules;

UCLASS(Blueprintable, NonTransient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MATERIALPERMUTER_API UHardSwapBatchComponentRules : public UHardSwapBatchComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterHardSwapRules HardSwapRules;
    
    UHardSwapBatchComponentRules();
    UFUNCTION(BlueprintCallable)
    static void CreateHardSwapBatchComponentWithRules(AActor* Owner, FMaterialPermuterHardSwapRules HardSwapSetup, TArray<AActor*> Actors, FHardSwapBatchComponentSettings BatchSettings, UHardSwapBatchComponentRules*& HardSwapBatchComponent);
    
};

