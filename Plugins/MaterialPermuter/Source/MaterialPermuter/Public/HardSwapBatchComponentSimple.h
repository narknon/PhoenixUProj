#pragma once
#include "CoreMinimal.h"
#include "HardSwapBatchComponent.h"
#include "HardSwapBatchComponentSettings.h"
#include "MaterialPermuterHardSwapSimple.h"
#include "HardSwapBatchComponentSimple.generated.h"

class AActor;
class UHardSwapBatchComponentSimple;

UCLASS(Blueprintable, NonTransient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MATERIALPERMUTER_API UHardSwapBatchComponentSimple : public UHardSwapBatchComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterHardSwapSimple HardSwapSimple;
    
    UHardSwapBatchComponentSimple();
    UFUNCTION(BlueprintCallable)
    static void CreateHardSwapBatchComponent(AActor* Owner, FMaterialPermuterHardSwapSimple HardSwapSetup, TArray<AActor*> Actors, FHardSwapBatchComponentSettings BatchSettings, UHardSwapBatchComponentSimple*& HardSwapBatchComponent);
    
};

