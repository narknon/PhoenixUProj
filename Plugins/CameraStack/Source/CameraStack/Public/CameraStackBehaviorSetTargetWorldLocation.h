#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorSetTargetWorldLocation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorSetTargetWorldLocation : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetWorldLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrimaryTargetOffsetFactor;
    
    UCameraStackBehaviorSetTargetWorldLocation();
};

