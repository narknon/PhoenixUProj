#pragma once
#include "CoreMinimal.h"
#include "CameraStackSplineGetter.h"
#include "CameraStackAvatarSyncSplineGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackAvatarSyncSplineGetter : public UCameraStackSplineGetter {
    GENERATED_BODY()
public:
    UCameraStackAvatarSyncSplineGetter();
};

