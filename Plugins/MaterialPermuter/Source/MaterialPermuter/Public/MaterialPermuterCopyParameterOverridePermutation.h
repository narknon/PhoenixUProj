#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterCopyParameterOverrideBase.h"
#include "MaterialPermuterPermutationProperty.h"
#include "MaterialPermuterCopyParameterOverridePermutation.generated.h"

USTRUCT(BlueprintType)
struct FMaterialPermuterCopyParameterOverridePermutation : public FMaterialPermuterCopyParameterOverrideBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterPermutationProperty Permutation;
    
    MATERIALPERMUTER_API FMaterialPermuterCopyParameterOverridePermutation();
};

