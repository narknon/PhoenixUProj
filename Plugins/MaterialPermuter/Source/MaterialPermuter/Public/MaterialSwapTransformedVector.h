#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapTransformedParameter.h"
#include "MaterialSwapTransformedVector.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapTransformedVector : public FMaterialSwapTransformedParameter {
    GENERATED_BODY()
public:
    FMaterialSwapTransformedVector();
};

