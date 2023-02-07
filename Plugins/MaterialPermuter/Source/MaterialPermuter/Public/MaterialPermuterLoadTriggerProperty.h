#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterNameProperty.h"
#include "MaterialPermuterLoadTriggerProperty.generated.h"

USTRUCT(BlueprintType)
struct FMaterialPermuterLoadTriggerProperty : public FMaterialPermuterNameProperty {
    GENERATED_BODY()
public:
    MATERIALPERMUTER_API FMaterialPermuterLoadTriggerProperty();
};

