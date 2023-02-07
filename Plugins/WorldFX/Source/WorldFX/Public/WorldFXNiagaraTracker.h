#pragma once
#include "CoreMinimal.h"
#include "WorldFXTracker.h"
#include "WorldFXNiagaraTracker.generated.h"

USTRUCT(BlueprintType)
struct FWorldFXNiagaraTracker : public FWorldFXTracker {
    GENERATED_BODY()
public:
    WORLDFX_API FWorldFXNiagaraTracker();
};

