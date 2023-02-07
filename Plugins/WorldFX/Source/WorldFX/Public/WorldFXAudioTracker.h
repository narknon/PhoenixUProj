#pragma once
#include "CoreMinimal.h"
#include "WorldFXTracker.h"
#include "WorldFXAudioTracker.generated.h"

USTRUCT(BlueprintType)
struct FWorldFXAudioTracker : public FWorldFXTracker {
    GENERATED_BODY()
public:
    WORLDFX_API FWorldFXAudioTracker();
};

