#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_CameraContext.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_CameraContext : public UBTDecorator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Context;
    
    UBTDecorator_CameraContext();
};

