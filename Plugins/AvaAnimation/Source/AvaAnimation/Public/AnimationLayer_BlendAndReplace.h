#pragma once
#include "CoreMinimal.h"
#include "AnimationRequestLayerInstance.h"
#include "AnimationLayer_BlendAndReplace.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimationLayer_BlendAndReplace : public FAnimationRequestLayerInstance {
    GENERATED_BODY()
public:
    FAnimationLayer_BlendAndReplace();
};

