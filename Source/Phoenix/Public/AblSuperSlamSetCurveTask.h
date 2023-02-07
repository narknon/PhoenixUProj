#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblSuperSlamCurveData.h"
#include "AblSuperSlamSetCurveTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSuperSlamSetCurveTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAblSuperSlamCurveData> Curves;
    
    UAblSuperSlamSetCurveTask();
};

