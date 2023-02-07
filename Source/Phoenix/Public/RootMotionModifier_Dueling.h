#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "RootMotionModifier_Dueling.generated.h"

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_Dueling : public URootMotionModifier {
    GENERATED_BODY()
public:
    URootMotionModifier_Dueling();
};

