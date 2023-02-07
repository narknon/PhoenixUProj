#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "RootMotionModifier_Telescope.generated.h"

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_Telescope : public URootMotionModifier {
    GENERATED_BODY()
public:
    URootMotionModifier_Telescope();
};

