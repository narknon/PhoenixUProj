#pragma once
#include "CoreMinimal.h"
#include "CameraStackSecondaryTargetGetterBlend.h"
#include "CameraStackDebugTargetGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackDebugTargetGetter : public UCameraStackSecondaryTargetGetterBlend {
    GENERATED_BODY()
public:
    UCameraStackDebugTargetGetter();
};

