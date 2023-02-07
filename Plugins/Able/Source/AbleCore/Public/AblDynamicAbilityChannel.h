#pragma once
#include "CoreMinimal.h"
#include "AblAbilityChannel.h"
#include "AblDynamicAbilityChannel.generated.h"

USTRUCT(BlueprintType)
struct ABLECORE_API FAblDynamicAbilityChannel : public FAblAbilityChannel {
    GENERATED_BODY()
public:
    FAblDynamicAbilityChannel();
};

