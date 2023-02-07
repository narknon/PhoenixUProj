#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblAnimationModifier.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblAnimationModifier : public UObject {
    GENERATED_BODY()
public:
    UAblAnimationModifier();
};

