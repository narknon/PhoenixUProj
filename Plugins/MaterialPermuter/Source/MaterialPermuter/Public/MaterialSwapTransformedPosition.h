#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapTransformedParameter.h"
#include "MaterialSwapTransformedPosition.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapTransformedPosition : public FMaterialSwapTransformedParameter {
    GENERATED_BODY()
public:
    FMaterialSwapTransformedPosition();
};

