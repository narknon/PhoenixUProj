#pragma once
#include "CoreMinimal.h"
#include "SkinFXMaterialScalarProperty.h"
#include "SkinFXParameterDriver.h"
#include "RemapScalarRange.h"
#include "SkinFXParameterDriverAutoFXScalar.generated.h"

class UFXAutoTriggerScalar;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USkinFXParameterDriverAutoFXScalar : public USkinFXParameterDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXMaterialScalarProperty Parameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerScalar* AutoTriggerScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRemapScalarRange RemapScalarRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseRemapScalarRange;
    
    USkinFXParameterDriverAutoFXScalar();
};

