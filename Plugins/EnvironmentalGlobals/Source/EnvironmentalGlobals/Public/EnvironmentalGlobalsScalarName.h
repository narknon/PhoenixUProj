#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsDropdownName.h"
#include "EnvironmentalGlobalsScalarName.generated.h"

USTRUCT(BlueprintType)
struct FEnvironmentalGlobalsScalarName : public FEnvironmentalGlobalsDropdownName {
    GENERATED_BODY()
public:
    ENVIRONMENTALGLOBALS_API FEnvironmentalGlobalsScalarName();
};

