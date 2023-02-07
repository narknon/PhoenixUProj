#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterNameProperty.h"
#include "MaterialPermuterPermutationProperty.generated.h"

USTRUCT(BlueprintType)
struct FMaterialPermuterPermutationProperty : public FMaterialPermuterNameProperty {
    GENERATED_BODY()
public:
    MATERIALPERMUTER_API FMaterialPermuterPermutationProperty();
};

