#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_JumpFallTimeout.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_JumpFallTimeout : public UBTDecorator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeLimit;
    
    UBTDecorator_JumpFallTimeout();
};

