#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstanceProxy.h"
#include "AnimInstanceProxy_RetrieveActorTransform.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimInstanceProxy_RetrieveActorTransform : public FAnimInstanceProxy {
    GENERATED_BODY()
public:
    FAnimInstanceProxy_RetrieveActorTransform();
};

