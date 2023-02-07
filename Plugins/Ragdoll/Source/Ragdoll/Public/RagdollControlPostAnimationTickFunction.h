#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "RagdollControlPostAnimationTickFunction.generated.h"

USTRUCT(BlueprintType)
struct FRagdollControlPostAnimationTickFunction : public FTickFunction {
    GENERATED_BODY()
public:
    RAGDOLL_API FRagdollControlPostAnimationTickFunction();
};

template<>
struct TStructOpsTypeTraits<FRagdollControlPostAnimationTickFunction> : public TStructOpsTypeTraitsBase2<FRagdollControlPostAnimationTickFunction>
{
    enum
    {
        WithCopy = false
    };
};

