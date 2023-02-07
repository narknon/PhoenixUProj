#pragma once
#include "CoreMinimal.h"
#include "CameraStackReticleTargetGetter.h"
#include "CameraStackLockOnTargetGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackLockOnTargetGetter : public UCameraStackReticleTargetGetter {
    GENERATED_BODY()
public:
    UCameraStackLockOnTargetGetter();
};

