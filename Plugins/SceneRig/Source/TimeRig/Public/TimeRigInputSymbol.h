#pragma once
#include "CoreMinimal.h"
#include "TimeRigEventSymbol.h"
#include "TimeRigInputSymbol.generated.h"

USTRUCT(BlueprintType)
struct TIMERIG_API FTimeRigInputSymbol : public FTimeRigEventSymbol {
    GENERATED_BODY()
public:
    FTimeRigInputSymbol();
};

