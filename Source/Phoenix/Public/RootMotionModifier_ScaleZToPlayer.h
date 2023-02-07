#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "RootMotionModifier_ScaleZToPlayer.generated.h"

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_ScaleZToPlayer : public URootMotionModifier {
    GENERATED_BODY()
public:
    URootMotionModifier_ScaleZToPlayer();
};

