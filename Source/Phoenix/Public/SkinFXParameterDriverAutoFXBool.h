#pragma once
#include "CoreMinimal.h"
#include "SkinFXMaterialScalarProperty.h"
#include "SkinFXParameterDriver.h"
#include "SkinFXParameterDriverAutoFXBool.generated.h"

class UFXAutoTriggerBool;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USkinFXParameterDriverAutoFXBool : public USkinFXParameterDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXMaterialScalarProperty Parameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerBool* AutoTriggerBool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ValueIfFalse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ValueIfTrue;
    
    USkinFXParameterDriverAutoFXBool();
};

