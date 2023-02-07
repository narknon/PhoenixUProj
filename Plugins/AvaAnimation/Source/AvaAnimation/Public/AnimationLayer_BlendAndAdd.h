#pragma once
#include "CoreMinimal.h"
#include "AnimationRequestLayerInstance.h"
#include "AnimationLayer_BlendAndAdd.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimationLayer_BlendAndAdd : public FAnimationRequestLayerInstance {
    GENERATED_BODY()
public:
    FAnimationLayer_BlendAndAdd();
};

