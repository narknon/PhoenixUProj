#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterLoadingPriority.h"
#include "MaterialPermuterLoadingStrategy.h"
#include "MaterialPermuterLoadingStrategies.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterLoadingStrategies {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FMaterialPermuterLoadingStrategy> Strategies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterLoadingStrategy DefaultStrategy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UMaterialInterface>> ManualPreloads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterLoadingPriority ManualPreloadPriority;
    
    FMaterialPermuterLoadingStrategies();
};

