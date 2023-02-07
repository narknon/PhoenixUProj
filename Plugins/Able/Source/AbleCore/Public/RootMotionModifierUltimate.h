#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "RootMotionModifierUltimate.generated.h"

UCLASS(Abstract, Blueprintable, NonTransient)
class ABLECORE_API URootMotionModifierUltimate : public URootMotionModifier {
    GENERATED_BODY()
public:
    URootMotionModifierUltimate();
};

