#pragma once
#include "CoreMinimal.h"
#include "CameraStackSecondaryTargetGetterBlend.h"
#include "CameraStackKillCamTargetGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackKillCamTargetGetter : public UCameraStackSecondaryTargetGetterBlend {
    GENERATED_BODY()
public:
    UCameraStackKillCamTargetGetter();
};

