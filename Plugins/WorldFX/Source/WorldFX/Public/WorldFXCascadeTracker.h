#pragma once
#include "CoreMinimal.h"
#include "WorldFXTracker.h"
#include "WorldFXCascadeTracker.generated.h"

USTRUCT(BlueprintType)
struct FWorldFXCascadeTracker : public FWorldFXTracker {
    GENERATED_BODY()
public:
    WORLDFX_API FWorldFXCascadeTracker();
};

