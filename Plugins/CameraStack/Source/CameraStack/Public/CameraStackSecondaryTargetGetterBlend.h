#pragma once
#include "CoreMinimal.h"
#include "CameraStackSecondaryTargetGetter.h"
#include "CameraStackSecondaryTargetGetterBlend.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackSecondaryTargetGetterBlend : public UCameraStackSecondaryTargetGetter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendDuration;
    
    UCameraStackSecondaryTargetGetterBlend();
};

