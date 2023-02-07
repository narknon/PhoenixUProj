#pragma once
#include "CoreMinimal.h"
#include "CameraStackSecondaryTargetGetter.h"
#include "CameraStackToolInteractionBeastTargetGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackToolInteractionBeastTargetGetter : public UCameraStackSecondaryTargetGetter {
    GENERATED_BODY()
public:
    UCameraStackToolInteractionBeastTargetGetter();
};

