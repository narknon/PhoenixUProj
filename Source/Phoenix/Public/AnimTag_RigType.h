#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitectTagProvider.h"
#include "AnimTag_RigType.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimTag_RigType : public UAnimationArchitectTagProvider {
    GENERATED_BODY()
public:
    UAnimTag_RigType();
};

