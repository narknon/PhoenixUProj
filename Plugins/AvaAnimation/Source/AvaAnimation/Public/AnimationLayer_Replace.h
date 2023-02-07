#pragma once
#include "CoreMinimal.h"
#include "AnimationRequestLayerInstance.h"
#include "AnimationLayer_Replace.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimationLayer_Replace : public FAnimationRequestLayerInstance {
    GENERATED_BODY()
public:
    FAnimationLayer_Replace();
};

