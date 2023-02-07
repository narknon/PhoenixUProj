#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorMultiCrossBlend.h"
#include "CameraStackBehaviorInfluenceCrossBlend.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, HideDropdown)
class CAMERASTACK_API UCameraStackBehaviorInfluenceCrossBlend : public UCameraStackBehaviorMultiCrossBlend {
    GENERATED_BODY()
public:
    UCameraStackBehaviorInfluenceCrossBlend();
};

