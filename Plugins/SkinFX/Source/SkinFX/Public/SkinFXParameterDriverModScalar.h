#pragma once
#include "CoreMinimal.h"
#include "SkinFXMaterialScalarProperty.h"
#include "SkinFXParameterDriverMod.h"
#include "SkinFXParameterDriverModScalar.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SKINFX_API USkinFXParameterDriverModScalar : public USkinFXParameterDriverMod {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXMaterialScalarProperty ModByParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDefaultValue;
    
    USkinFXParameterDriverModScalar();
};

