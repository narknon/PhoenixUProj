#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblAnimationEndCallback.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblAnimationEndCallback : public UObject {
    GENERATED_BODY()
public:
    UAblAnimationEndCallback();
};

