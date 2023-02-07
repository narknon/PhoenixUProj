#pragma once
#include "CoreMinimal.h"
#include "IKDriver.h"
#include "IKDriver_AimAtControl.h"
#include "IKDriver_AimAt.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UIKDriver_AimAt : public UIKDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIKDriver_AimAtControl> AimControls;
    
    UIKDriver_AimAt();
};

