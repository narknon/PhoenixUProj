#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "CameraPreUpdateTickFunction.generated.h"

USTRUCT(BlueprintType)
struct FCameraPreUpdateTickFunction : public FTickFunction {
    GENERATED_BODY()
public:
    CAMERASTACK_API FCameraPreUpdateTickFunction();
};

template<>
struct TStructOpsTypeTraits<FCameraPreUpdateTickFunction> : public TStructOpsTypeTraitsBase2<FCameraPreUpdateTickFunction>
{
    enum
    {
        WithCopy = false
    };
};

