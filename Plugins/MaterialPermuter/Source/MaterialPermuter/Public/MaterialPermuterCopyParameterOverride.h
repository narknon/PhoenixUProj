#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterParameterCopy.h"
#include "MaterialPermuterCopyParameterOverride.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterCopyParameterOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UMaterialInterface>> SpecificMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterParameterCopy ParameterCopy;
    
    FMaterialPermuterCopyParameterOverride();
};

