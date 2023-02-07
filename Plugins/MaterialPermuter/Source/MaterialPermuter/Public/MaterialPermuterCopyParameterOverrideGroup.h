#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterCopyParameterOverrideBase.h"
#include "MaterialPermuterGroupProperty.h"
#include "MaterialPermuterCopyParameterOverrideGroup.generated.h"

USTRUCT(BlueprintType)
struct FMaterialPermuterCopyParameterOverrideGroup : public FMaterialPermuterCopyParameterOverrideBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterGroupProperty Group;
    
    MATERIALPERMUTER_API FMaterialPermuterCopyParameterOverrideGroup();
};

