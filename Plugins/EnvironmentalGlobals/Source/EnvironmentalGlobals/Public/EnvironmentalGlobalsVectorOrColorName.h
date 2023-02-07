#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsDropdownName.h"
#include "EnvironmentalGlobalsVectorOrColorName.generated.h"

USTRUCT(BlueprintType)
struct FEnvironmentalGlobalsVectorOrColorName : public FEnvironmentalGlobalsDropdownName {
    GENERATED_BODY()
public:
    ENVIRONMENTALGLOBALS_API FEnvironmentalGlobalsVectorOrColorName();
};

