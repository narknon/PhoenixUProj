#pragma once
#include "CoreMinimal.h"
#include "TimeInput.h"
#include "WorldFXRuleTime.h"
#include "WorldFXRuleTimeInRange.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleTimeInRange : public UWorldFXRuleTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeInput StartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeInput EndTime;
    
    UWorldFXRuleTimeInRange();
};

