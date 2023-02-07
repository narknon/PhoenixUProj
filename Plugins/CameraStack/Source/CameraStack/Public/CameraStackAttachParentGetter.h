#pragma once
#include "CoreMinimal.h"
#include "CameraStackSecondaryTargetGetter.h"
#include "CameraStackAttachParentGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackAttachParentGetter : public UCameraStackSecondaryTargetGetter {
    GENERATED_BODY()
public:
    UCameraStackAttachParentGetter();
};

