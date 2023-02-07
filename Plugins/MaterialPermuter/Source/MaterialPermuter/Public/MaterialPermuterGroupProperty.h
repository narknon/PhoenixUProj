#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterNameProperty.h"
#include "MaterialPermuterGroupProperty.generated.h"

USTRUCT(BlueprintType)
struct FMaterialPermuterGroupProperty : public FMaterialPermuterNameProperty {
    GENERATED_BODY()
public:
    MATERIALPERMUTER_API FMaterialPermuterGroupProperty();
};

