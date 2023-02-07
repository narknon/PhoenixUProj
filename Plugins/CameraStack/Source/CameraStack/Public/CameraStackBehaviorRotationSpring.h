#pragma once
#include "CoreMinimal.h"
#include "CameraOptionName.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorRotationSpring.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorRotationSpring : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Frequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DampingRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraOptionName FilteringAmountOptionName;
    
    UCameraStackBehaviorRotationSpring();
};

