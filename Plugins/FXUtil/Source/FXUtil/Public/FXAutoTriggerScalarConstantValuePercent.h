#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "FXAutoTriggerScalarConstantValuePercent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarConstantValuePercent : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UFXAutoTriggerScalarConstantValuePercent();
};

