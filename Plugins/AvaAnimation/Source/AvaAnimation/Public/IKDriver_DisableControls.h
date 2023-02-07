#pragma once
#include "CoreMinimal.h"
#include "IKDriver.h"
#include "IKDriver_DisableControls.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UIKDriver_DisableControls : public UIKDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AlphaControlsToDisable;
    
    UIKDriver_DisableControls();
};

