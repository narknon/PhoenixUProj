#pragma once
#include "CoreMinimal.h"
#include "CameraStackAvatarTargetTrackerGetterBase.h"
#include "CameraStackAvatarAimAtTargetGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackAvatarAimAtTargetGetter : public UCameraStackAvatarTargetTrackerGetterBase {
    GENERATED_BODY()
public:
    UCameraStackAvatarAimAtTargetGetter();
};

