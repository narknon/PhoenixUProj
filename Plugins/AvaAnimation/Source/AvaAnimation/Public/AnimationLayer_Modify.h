#pragma once
#include "CoreMinimal.h"
#include "AnimationRequestLayerInstance.h"
#include "AnimationLayer_Modify.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimationLayer_Modify : public FAnimationRequestLayerInstance {
    GENERATED_BODY()
public:
    FAnimationLayer_Modify();
};

