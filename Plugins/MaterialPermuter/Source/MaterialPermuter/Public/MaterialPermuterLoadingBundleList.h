#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterLoadingBundleList.generated.h"

class UMaterialPermuterLoadingBundle;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterLoadingBundleList {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UMaterialPermuterLoadingBundle>> Bundles;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UMaterialPermuterLoadingBundle>> QueuedBundles;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UMaterialPermuterLoadingBundle>> RemoveBundles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bProcessing;
    
public:
    FMaterialPermuterLoadingBundleList();
};

