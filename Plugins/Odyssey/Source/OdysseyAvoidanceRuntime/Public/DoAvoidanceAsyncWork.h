#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "DoAvoidanceAsyncWork.generated.h"

USTRUCT(BlueprintType)
struct FDoAvoidanceAsyncWork : public FTickFunction {
    GENERATED_BODY()
public:
    ODYSSEYAVOIDANCERUNTIME_API FDoAvoidanceAsyncWork();
};

template<>
struct TStructOpsTypeTraits<FDoAvoidanceAsyncWork> : public TStructOpsTypeTraitsBase2<FDoAvoidanceAsyncWork>
{
    enum
    {
        WithCopy = false
    };
};

