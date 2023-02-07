#pragma once
#include "CoreMinimal.h"
#include "AblAnimationChannel.h"
#include "AblDynamicAnimationChannel.generated.h"

USTRUCT(BlueprintType)
struct ABLECORE_API FAblDynamicAnimationChannel : public FAblAnimationChannel {
    GENERATED_BODY()
public:
    FAblDynamicAnimationChannel();
};

