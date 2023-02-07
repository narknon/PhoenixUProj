#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "FXAutoTriggerScalarTwoParams.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarTwoParams : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerScalar* A;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerScalar* B;
    
    UFXAutoTriggerScalarTwoParams();
};

