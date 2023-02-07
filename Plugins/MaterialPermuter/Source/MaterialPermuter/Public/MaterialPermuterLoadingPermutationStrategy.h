#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterLoadingStrategy.h"
#include "MaterialPermuterPermutationProperty.h"
#include "MaterialPermuterLoadingPermutationStrategy.generated.h"

USTRUCT(BlueprintType)
struct FMaterialPermuterLoadingPermutationStrategy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterPermutationProperty Permutation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterLoadingStrategy Strategy;
    
    MATERIALPERMUTER_API FMaterialPermuterLoadingPermutationStrategy();
};

