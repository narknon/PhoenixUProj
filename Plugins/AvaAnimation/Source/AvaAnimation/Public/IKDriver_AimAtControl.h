#pragma once
#include "CoreMinimal.h"
#include "EAnimationDirections.h"
#include "IKTaskReferenceProperty.h"
#include "IKDriver_AimAtControl.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FIKDriver_AimAtControl {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKTaskReferenceProperty Task;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimationDirections DirectionDriver;
    
    FIKDriver_AimAtControl();
};

