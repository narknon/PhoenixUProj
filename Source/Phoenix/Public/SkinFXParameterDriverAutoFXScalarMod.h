#pragma once
#include "CoreMinimal.h"
#include "SkinFXParameterDriverMod.h"
#include "RemapScalarRange.h"
#include "SkinFXParameterDriverAutoFXScalarMod.generated.h"

class UFXAutoTriggerScalar;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USkinFXParameterDriverAutoFXScalarMod : public USkinFXParameterDriverMod {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerScalar* AutoTriggerScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRemapScalarRange RemapScalarRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseRemapScalarRange;
    
    USkinFXParameterDriverAutoFXScalarMod();
};

