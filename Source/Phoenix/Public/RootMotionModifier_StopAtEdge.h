#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "RootMotionModifier_StopAtEdge.generated.h"

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_StopAtEdge : public URootMotionModifier {
    GENERATED_BODY()
public:
    URootMotionModifier_StopAtEdge();
};

