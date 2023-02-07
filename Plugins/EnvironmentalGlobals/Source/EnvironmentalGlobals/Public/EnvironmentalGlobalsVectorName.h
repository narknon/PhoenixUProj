#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsDropdownName.h"
#include "EnvironmentalGlobalsVectorName.generated.h"

USTRUCT(BlueprintType)
struct FEnvironmentalGlobalsVectorName : public FEnvironmentalGlobalsDropdownName {
    GENERATED_BODY()
public:
    ENVIRONMENTALGLOBALS_API FEnvironmentalGlobalsVectorName();
};

