#pragma once
#include "CoreMinimal.h"
#include "AnimationRequestLayerInstance.h"
#include "AnimationLayer_Additive.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimationLayer_Additive : public FAnimationRequestLayerInstance {
    GENERATED_BODY()
public:
    FAnimationLayer_Additive();
};

