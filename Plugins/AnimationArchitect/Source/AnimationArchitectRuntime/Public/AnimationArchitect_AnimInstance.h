#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimationArchitect_AnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ANIMATIONARCHITECTRUNTIME_API UAnimationArchitect_AnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UAnimationArchitect_AnimInstance();
};

