#pragma once
#include "CoreMinimal.h"
#include "WorldFXPrimitiveAdvancedOptions.h"
#include "WorldFXNiagaraSystemAdvancedOptions.generated.h"

USTRUCT(BlueprintType)
struct WORLDFX_API FWorldFXNiagaraSystemAdvancedOptions : public FWorldFXPrimitiveAdvancedOptions {
    GENERATED_BODY()
public:
    FWorldFXNiagaraSystemAdvancedOptions();
};

