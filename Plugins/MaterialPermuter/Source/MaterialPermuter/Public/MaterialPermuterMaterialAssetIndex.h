#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterLoadingStrategy.h"
#include "MaterialPermuterMaterialAssetIndexEntry.h"
#include "MaterialPermuterMaterialAssetIndex.generated.h"

class UMaterialPermuterLoadingStrategiesAsset;

USTRUCT(BlueprintType)
struct FMaterialPermuterMaterialAssetIndex {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialPermuterLoadingStrategiesAsset* LoadingStrategies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterLoadingStrategy DefaultStrategy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialPermuterMaterialAssetIndexEntry> Assets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 OnAsset;
    
    MATERIALPERMUTER_API FMaterialPermuterMaterialAssetIndex();
};

