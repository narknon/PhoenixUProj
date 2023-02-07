#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsDropdownName.h"
#include "EnvironmentalGlobalsColorName.generated.h"

USTRUCT(BlueprintType)
struct FEnvironmentalGlobalsColorName : public FEnvironmentalGlobalsDropdownName {
    GENERATED_BODY()
public:
    ENVIRONMENTALGLOBALS_API FEnvironmentalGlobalsColorName();
};

