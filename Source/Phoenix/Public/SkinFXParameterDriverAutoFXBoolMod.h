#pragma once
#include "CoreMinimal.h"
#include "SkinFXParameterDriverMod.h"
#include "SkinFXParameterDriverAutoFXBoolMod.generated.h"

class UFXAutoTriggerBool;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USkinFXParameterDriverAutoFXBoolMod : public USkinFXParameterDriverMod {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerBool* AutoTriggerBool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ModIfFalse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ModIfTrue;
    
    USkinFXParameterDriverAutoFXBoolMod();
};

