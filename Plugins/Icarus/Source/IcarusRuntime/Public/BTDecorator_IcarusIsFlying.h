#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IcarusIsFlying.generated.h"

UCLASS(Blueprintable)
class ICARUSRUNTIME_API UBTDecorator_IcarusIsFlying : public UBTDecorator {
    GENERATED_BODY()
public:
    UBTDecorator_IcarusIsFlying();
};

