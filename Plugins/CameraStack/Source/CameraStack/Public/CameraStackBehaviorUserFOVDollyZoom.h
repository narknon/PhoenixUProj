#pragma once
#include "CoreMinimal.h"
#include "CameraOptionName.h"
#include "CameraStackBehaviorDollyZoom.h"
#include "CameraStackBehaviorUserFOVDollyZoom.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorUserFOVDollyZoom : public UCameraStackBehaviorDollyZoom {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraOptionName FieldOfViewOffsetOptionName;
    
    UCameraStackBehaviorUserFOVDollyZoom();
};

