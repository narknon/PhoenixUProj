#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "FXAutoTriggerScalarFromBool.generated.h"

class UFXAutoTriggerBool;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarFromBool : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerBool* Condition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TrueValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FalseValue;
    
    UFXAutoTriggerScalarFromBool();
};

