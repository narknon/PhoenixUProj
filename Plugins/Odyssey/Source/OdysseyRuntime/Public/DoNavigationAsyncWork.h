#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "DoNavigationAsyncWork.generated.h"

USTRUCT(BlueprintType)
struct FDoNavigationAsyncWork : public FTickFunction {
    GENERATED_BODY()
public:
    ODYSSEYRUNTIME_API FDoNavigationAsyncWork();
};

template<>
struct TStructOpsTypeTraits<FDoNavigationAsyncWork> : public TStructOpsTypeTraitsBase2<FDoNavigationAsyncWork>
{
    enum
    {
        WithCopy = false
    };
};

