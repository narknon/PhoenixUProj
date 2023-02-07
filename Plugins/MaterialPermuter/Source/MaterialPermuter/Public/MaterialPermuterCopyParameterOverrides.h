#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterCopyParameterOverride.h"
#include "MaterialPermuterCopyParameterOverrides.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterCopyParameterOverrides {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialPermuterCopyParameterOverride> Groups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialPermuterCopyParameterOverride> Permutations;
    
    FMaterialPermuterCopyParameterOverrides();
};

