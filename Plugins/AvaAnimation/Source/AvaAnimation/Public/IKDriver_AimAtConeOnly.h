#pragma once
#include "CoreMinimal.h"
#include "IKDriver.h"
#include "IKDriver_AimAtConeOnlyControl.h"
#include "IKDriver_AimAtConeOnly.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UIKDriver_AimAtConeOnly : public UIKDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIKDriver_AimAtConeOnlyControl> AimControls;
    
    UIKDriver_AimAtConeOnly();
};

