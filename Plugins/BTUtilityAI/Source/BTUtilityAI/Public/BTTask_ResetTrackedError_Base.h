#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_ResetTrackedError_Base.generated.h"

UCLASS(Abstract, Blueprintable)
class UBTTask_ResetTrackedError_Base : public UBTTaskNode {
    GENERATED_BODY()
public:
    UBTTask_ResetTrackedError_Base();
};

