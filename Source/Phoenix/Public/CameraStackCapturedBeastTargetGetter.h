#pragma once
#include "CoreMinimal.h"
#include "CameraStackSecondaryTargetGetter.h"
#include "CameraStackCapturedBeastTargetGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackCapturedBeastTargetGetter : public UCameraStackSecondaryTargetGetter {
    GENERATED_BODY()
public:
    UCameraStackCapturedBeastTargetGetter();
};

