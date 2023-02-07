#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SkinFXAutoTriggerDriver.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class SKINFX_API USkinFXAutoTriggerDriver : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDisabled;
    
    USkinFXAutoTriggerDriver();
};

