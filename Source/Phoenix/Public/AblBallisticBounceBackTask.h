#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblBallisticBounceBackTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBallisticBounceBackTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Speed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Gravity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ChooseRandomDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAngle;
    
public:
    UAblBallisticBounceBackTask();
};

