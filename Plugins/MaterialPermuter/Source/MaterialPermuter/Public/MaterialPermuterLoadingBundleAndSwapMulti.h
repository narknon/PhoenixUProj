#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterLoadingPriority.h"
#include "MaterialPermuterLoadingBundleAndSwap.h"
#include "MaterialPermuterLoadingBundleAndSwapTarget.h"
#include "MaterialPermuterLoadingBundleAndSwapWeakTarget.h"
#include "MaterialSwapKeyUI.h"
#include "MaterialPermuterLoadingBundleAndSwapMulti.generated.h"

class AActor;
class UMaterialPermuterLoadingBundleAndSwapMulti;

UCLASS(Blueprintable, NonTransient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MATERIALPERMUTER_API UMaterialPermuterLoadingBundleAndSwapMulti : public UMaterialPermuterLoadingBundleAndSwap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialPermuterLoadingBundleAndSwapWeakTarget> TargetsToSwap;
    
    UMaterialPermuterLoadingBundleAndSwapMulti();
    UFUNCTION(BlueprintCallable)
    static UMaterialPermuterLoadingBundleAndSwapMulti* CreateAndSwapMultiTargets(AActor* Owner, FMaterialSwapKeyUI SwapInfo, TArray<FMaterialPermuterLoadingBundleAndSwapTarget> SwapTargets, EMaterialPermuterLoadingPriority LoadPriority);
    
    UFUNCTION(BlueprintCallable)
    static UMaterialPermuterLoadingBundleAndSwapMulti* CreateAndSwapMultiTarget(AActor* Owner, FMaterialSwapKeyUI SwapInfo, FMaterialPermuterLoadingBundleAndSwapTarget SwapTarget, EMaterialPermuterLoadingPriority LoadPriority);
    
};

