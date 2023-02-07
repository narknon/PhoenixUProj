#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MotionMatcherBPInterface.generated.h"

class UObject;

UINTERFACE(Blueprintable, MinimalAPI)
class UMotionMatcherBPInterface : public UInterface {
    GENERATED_BODY()
};

class IMotionMatcherBPInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UObject* GetGoalDelegate();
    
};

