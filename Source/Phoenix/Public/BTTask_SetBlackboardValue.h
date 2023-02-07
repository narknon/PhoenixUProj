#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTTask_SetBlackboardValue.generated.h"

UCLASS(Abstract, Blueprintable)
class UBTTask_SetBlackboardValue : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector Key;
    
    UBTTask_SetBlackboardValue();
};

