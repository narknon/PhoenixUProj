#pragma once
#include "CoreMinimal.h"
#include "SkinFXMaterialParamProperty.h"
#include "SkinFXParameterDriver.h"
#include "SkinFXParameterDriverMod.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class SKINFX_API USkinFXParameterDriverMod : public USkinFXParameterDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXMaterialParamProperty Parameter;
    
    USkinFXParameterDriverMod();
};

