#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterLoadingBundleAndSwapType.h"
#include "HardSwapBatchComponentSettings.h"
#include "MaterialSwapParameters.h"
#include "MaterialPermuterLoadingBundleAndSwapTarget.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterLoadingBundleAndSwapTarget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ActorsToSwap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters InitialParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterLoadingBundleAndSwapType SwapType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHardSwapBatchComponentSettings HardSwapBatchSettings;
    
    FMaterialPermuterLoadingBundleAndSwapTarget();
};

