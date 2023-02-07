#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterLoadingBundleAndSwapType.h"
#include "HardSwapBatchComponentSettings.h"
#include "MaterialSwapParameters.h"
#include "MaterialPermuterLoadingBundleAndSwapWeakTarget.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterLoadingBundleAndSwapWeakTarget {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> ActorsToSwap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters InitialParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterLoadingBundleAndSwapType SwapType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHardSwapBatchComponentSettings HardSwapBatchSettings;
    
    FMaterialPermuterLoadingBundleAndSwapWeakTarget();
};

