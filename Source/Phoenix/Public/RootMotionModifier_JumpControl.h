#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "RootMotionModifier_JumpControl.generated.h"

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_JumpControl : public URootMotionModifier {
    GENERATED_BODY()
public:
    URootMotionModifier_JumpControl();
};

