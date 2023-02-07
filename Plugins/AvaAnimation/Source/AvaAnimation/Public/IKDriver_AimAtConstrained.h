#pragma once
#include "CoreMinimal.h"
#include "IKDriver.h"
#include "IKDriver_AimAtConstrainedControl.h"
#include "IKDriver_AimAtConstrained.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UIKDriver_AimAtConstrained : public UIKDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIKDriver_AimAtConstrainedControl> AimControls;
    
    UIKDriver_AimAtConstrained();
};

