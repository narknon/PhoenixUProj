#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "RootMotionModifier_EdgeCheck.generated.h"

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_EdgeCheck : public URootMotionModifier {
    GENERATED_BODY()
public:
    URootMotionModifier_EdgeCheck();
};

