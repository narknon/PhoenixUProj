#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitectTagProvider.h"
#include "StationTag_Character.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UStationTag_Character : public UAnimationArchitectTagProvider {
    GENERATED_BODY()
public:
    UStationTag_Character();
};

