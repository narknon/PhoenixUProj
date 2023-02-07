#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_CameraInputTimeout.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_CameraInputTimeout : public UBTDecorator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeLimit;
    
    UBTDecorator_CameraInputTimeout();
};

