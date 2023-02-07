#pragma once
#include "CoreMinimal.h"
#include "CameraStackSecondaryTargetGetterBlend.h"
#include "CameraStackAvatarTargetTrackerGetterBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackAvatarTargetTrackerGetterBase : public UCameraStackSecondaryTargetGetterBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseActorCenterIfApplicable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseRootBoneIfApplicable;
    
    UCameraStackAvatarTargetTrackerGetterBase();
};

