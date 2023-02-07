#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorAddArmLength.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorAddArmLength : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ArmLengthOffset;
    
    UCameraStackBehaviorAddArmLength();
};

