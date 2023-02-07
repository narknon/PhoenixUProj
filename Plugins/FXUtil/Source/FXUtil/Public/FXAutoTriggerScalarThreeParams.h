#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "FXAutoTriggerScalarThreeParams.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarThreeParams : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerScalar* A;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerScalar* B;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerScalar* C;
    
    UFXAutoTriggerScalarThreeParams();
};

