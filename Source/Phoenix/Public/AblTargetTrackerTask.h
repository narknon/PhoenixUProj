#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ETargetID.h"
#include "ETask_TargetTrackerType.h"
#include "ETask_TargetType.h"
#include "AblTargetTrackerTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblTargetTrackerTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETask_TargetTrackerType TargetTrackerType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETask_TargetType TargetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETargetID::Type> TargetPriority;
    
public:
    UAblTargetTrackerTask();
};

