#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_Wait.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTTask_WaitBlackboardTimeWithDeviation.generated.h"

UCLASS(Blueprintable)
class UBTTask_WaitBlackboardTimeWithDeviation : public UBTTask_Wait {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector BlackboardKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Deviation;
    
public:
    UBTTask_WaitBlackboardTimeWithDeviation();
};

