#pragma once
#include "CoreMinimal.h"
#include "TimeRigEventSymbol.h"
#include "TimeRigOutputSymbol.generated.h"

USTRUCT(BlueprintType)
struct TIMERIG_API FTimeRigOutputSymbol : public FTimeRigEventSymbol {
    GENERATED_BODY()
public:
    FTimeRigOutputSymbol();
};

