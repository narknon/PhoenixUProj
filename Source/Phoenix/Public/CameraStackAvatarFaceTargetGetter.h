#pragma once
#include "CoreMinimal.h"
#include "CameraStackAvatarTargetTrackerGetterBase.h"
#include "CameraStackAvatarFaceTargetGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackAvatarFaceTargetGetter : public UCameraStackAvatarTargetTrackerGetterBase {
    GENERATED_BODY()
public:
    UCameraStackAvatarFaceTargetGetter();
};

