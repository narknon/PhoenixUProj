#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "BudgeterTickFunction.generated.h"

USTRUCT(BlueprintType)
struct FBudgeterTickFunction : public FTickFunction {
    GENERATED_BODY()
public:
    PHOENIXSIGNIFICANCEMANAGER_API FBudgeterTickFunction();
};

template<>
struct TStructOpsTypeTraits<FBudgeterTickFunction> : public TStructOpsTypeTraitsBase2<FBudgeterTickFunction>
{
    enum
    {
        WithCopy = false
    };
};

