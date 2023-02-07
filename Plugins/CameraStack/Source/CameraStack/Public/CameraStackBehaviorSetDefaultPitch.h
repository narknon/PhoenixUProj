#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehavior.h"
#include "CameraStackBehaviorSetDefaultPitch.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorSetDefaultPitch : public UCameraStackBehavior {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* ResetCurve;
    
    UCameraStackBehaviorSetDefaultPitch();
};

