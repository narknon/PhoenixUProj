#pragma once
#include "CoreMinimal.h"
#include "AnimationClip_TagLookupOnStationArchitect.h"
#include "AnimationClip_TagLookupOnAllArchitects.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UAnimationClip_TagLookupOnAllArchitects : public UAnimationClip_TagLookupOnStationArchitect {
    GENERATED_BODY()
public:
    UAnimationClip_TagLookupOnAllArchitects();
};

