#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "RootMotionModifier_Multiplier.generated.h"

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_Multiplier : public URootMotionModifier {
    GENERATED_BODY()
public:
    URootMotionModifier_Multiplier();
};

