#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterNameProperty.h"
#include "MaterialPermuterKeyProperty.generated.h"

USTRUCT(BlueprintType)
struct FMaterialPermuterKeyProperty : public FMaterialPermuterNameProperty {
    GENERATED_BODY()
public:
    MATERIALPERMUTER_API FMaterialPermuterKeyProperty();
};

