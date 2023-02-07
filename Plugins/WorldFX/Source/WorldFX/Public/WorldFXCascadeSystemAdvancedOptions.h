#pragma once
#include "CoreMinimal.h"
#include "WorldFXPrimitiveAdvancedOptions.h"
#include "WorldFXCascadeSystemAdvancedOptions.generated.h"

USTRUCT(BlueprintType)
struct WORLDFX_API FWorldFXCascadeSystemAdvancedOptions : public FWorldFXPrimitiveAdvancedOptions {
    GENERATED_BODY()
public:
    FWorldFXCascadeSystemAdvancedOptions();
};

