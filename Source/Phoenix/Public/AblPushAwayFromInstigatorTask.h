#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblPushAwayFromInstigatorTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblPushAwayFromInstigatorTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Distance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Speed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bContinuousDistanceCheck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeCapsuleSizeInDistanceCheck;
    
public:
    UAblPushAwayFromInstigatorTask();
};

