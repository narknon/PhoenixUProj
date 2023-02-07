#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterLoadingBundleAndSwapType.h"
#include "EMaterialPermuterLoadingPriority.h"
#include "HardSwapBatchComponentSettings.h"
#include "MaterialPermuterLoadingBundleAndSwap.h"
#include "MaterialSwapKeyUI.h"
#include "MaterialSwapParameters.h"
#include "MaterialPermuterLoadingBundleAndSwapOwner.generated.h"

class AActor;
class UMaterialPermuterLoadingBundleAndSwapOwner;

UCLASS(Blueprintable, NonTransient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MATERIALPERMUTER_API UMaterialPermuterLoadingBundleAndSwapOwner : public UMaterialPermuterLoadingBundleAndSwap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters InitialSwapParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterLoadingBundleAndSwapType SwapType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHardSwapBatchComponentSettings HardSwapBatchSettings;
    
    UMaterialPermuterLoadingBundleAndSwapOwner();
    UFUNCTION(BlueprintCallable)
    static UMaterialPermuterLoadingBundleAndSwapOwner* CreateAndSwapOwner(AActor* Owner, FMaterialSwapKeyUI SwapInfo, FMaterialSwapParameters InitialParameters, EMaterialPermuterLoadingBundleAndSwapType MaterialSwapType, EMaterialPermuterLoadingPriority LoadPriority);
    
};

