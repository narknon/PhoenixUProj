#pragma once
#include "CoreMinimal.h"
#include "AvaMotionWarpingModifier.h"
#include "AvaMotionWarpingModifier_OrientToRequest.generated.h"

USTRUCT(BlueprintType)
struct AMBULATORY_API FAvaMotionWarpingModifier_OrientToRequest : public FAvaMotionWarpingModifier {
    GENERATED_BODY()
public:
    FAvaMotionWarpingModifier_OrientToRequest();
};

