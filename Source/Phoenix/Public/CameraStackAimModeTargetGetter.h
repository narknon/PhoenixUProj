#pragma once
#include "CoreMinimal.h"
#include "CameraStackLockOnTargetGetter.h"
#include "CameraStackAimModeTargetGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackAimModeTargetGetter : public UCameraStackLockOnTargetGetter {
    GENERATED_BODY()
public:
    UCameraStackAimModeTargetGetter();
};

