#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorDollyZoom.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorDollyZoom : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FieldOfView;
    
public:
    UCameraStackBehaviorDollyZoom();
};

