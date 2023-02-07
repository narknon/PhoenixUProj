#pragma once
#include "CoreMinimal.h"
#include "LocatorTracker.h"
#include "AbsoluteTracker.generated.h"

USTRUCT(BlueprintType)
struct SKINFX_API FAbsoluteTracker : public FLocatorTracker {
    GENERATED_BODY()
public:
    FAbsoluteTracker();
};

