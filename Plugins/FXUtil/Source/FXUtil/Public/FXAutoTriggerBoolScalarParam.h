#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "FXAutoTriggerBoolScalarParam.generated.h"

class UFXAutoTriggerScalar;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolScalarParam : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerScalar* Scalar;
    
    UFXAutoTriggerBoolScalarParam();
};

