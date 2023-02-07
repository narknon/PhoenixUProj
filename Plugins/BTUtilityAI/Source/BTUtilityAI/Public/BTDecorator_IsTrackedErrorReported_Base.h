#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IsTrackedErrorReported_Base.generated.h"

UCLASS(Abstract, Blueprintable)
class UBTDecorator_IsTrackedErrorReported_Base : public UBTDecorator {
    GENERATED_BODY()
public:
    UBTDecorator_IsTrackedErrorReported_Base();
};

