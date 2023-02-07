#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AmbulatoryAnimTask.h"
#include "AmbulatoryTurnAssistAnimTask.generated.h"

class UCurveFloat;

UCLASS(Abstract, Blueprintable)
class AMBULATORY_API UAmbulatoryTurnAssistAnimTask : public UAmbulatoryAnimTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseFixedDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* TurnAssistCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* TurnAssistTimeMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ResetTimerWithinRange;
    
    UAmbulatoryTurnAssistAnimTask();
};

