#pragma once
#include "CoreMinimal.h"
#include "CameraStackSecondaryTargetGetterBlend.h"
#include "CameraStackReticleTargetGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackReticleTargetGetter : public UCameraStackSecondaryTargetGetterBlend {
    GENERATED_BODY()
public:
    UCameraStackReticleTargetGetter();
};

