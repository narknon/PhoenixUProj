#pragma once
#include "CoreMinimal.h"
#include "AvaMotionWarpingModifier_Warp.h"
#include "AvaMotionWarpingModifier_SkewWarp.generated.h"

USTRUCT(BlueprintType)
struct AMBULATORY_API FAvaMotionWarpingModifier_SkewWarp : public FAvaMotionWarpingModifier_Warp {
    GENERATED_BODY()
public:
    FAvaMotionWarpingModifier_SkewWarp();
};

