#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "AbilityComponentPostAnimationTickFunction.generated.h"

USTRUCT(BlueprintType)
struct FAbilityComponentPostAnimationTickFunction : public FTickFunction {
    GENERATED_BODY()
public:
    ABLECORE_API FAbilityComponentPostAnimationTickFunction();
};

template<>
struct TStructOpsTypeTraits<FAbilityComponentPostAnimationTickFunction> : public TStructOpsTypeTraitsBase2<FAbilityComponentPostAnimationTickFunction>
{
    enum
    {
        WithCopy = false
    };
};

