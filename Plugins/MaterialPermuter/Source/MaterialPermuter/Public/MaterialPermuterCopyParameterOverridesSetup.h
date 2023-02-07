#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterCopyParameterOverrideGroup.h"
#include "MaterialPermuterCopyParameterOverridePermutation.h"
#include "MaterialPermuterCopyParameterOverridesSetup.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterCopyParameterOverridesSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialPermuterCopyParameterOverrideGroup> GroupOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialPermuterCopyParameterOverridePermutation> PermutationOverrides;
    
    FMaterialPermuterCopyParameterOverridesSetup();
};

