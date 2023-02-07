#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "RootMotionModifier_CharacterScale.generated.h"

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_CharacterScale : public URootMotionModifier {
    GENERATED_BODY()
public:
    URootMotionModifier_CharacterScale();
};

