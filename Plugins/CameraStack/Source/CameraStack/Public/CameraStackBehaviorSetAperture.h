#pragma once
#include "CoreMinimal.h"
#include "CameraOptionName.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorSetAperture.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorSetAperture : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Aperture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraOptionName ApertureOptionName;
    
    UCameraStackBehaviorSetAperture();
};

