#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterParameterCopy.h"
#include "MaterialPermuterCopyParameterOverrideBase.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FMaterialPermuterCopyParameterOverrideBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterParameterCopy ParameterCopy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UMaterialInterface>> SpecificMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlySpecificMaterials;
    
    MATERIALPERMUTER_API FMaterialPermuterCopyParameterOverrideBase();
};

