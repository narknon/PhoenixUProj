#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblSuperSlamCurveData.h"
#include "AblSuperSlamTask.generated.h"

class UMultiFX2_Base;

UCLASS(Blueprintable, EditInlineNew)
class UAblSuperSlamTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAblSuperSlamCurveData> Curves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> HitFx;
    
    UAblSuperSlamTask();
};

