#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "RootMotionModifier_TargetTracker.generated.h"

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_TargetTracker : public URootMotionModifier {
    GENERATED_BODY()
public:
    URootMotionModifier_TargetTracker();
};

