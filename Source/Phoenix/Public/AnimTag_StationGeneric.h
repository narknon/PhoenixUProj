#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitectTagProvider.h"
#include "AnimTag_StationGeneric.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimTag_StationGeneric : public UAnimationArchitectTagProvider {
    GENERATED_BODY()
public:
    UAnimTag_StationGeneric();
};

