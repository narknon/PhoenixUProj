#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FeatureVector.h"
#include "MotionMatcherGoalInterface.generated.h"

class ACharacter;

UINTERFACE(Blueprintable, MinimalAPI)
class UMotionMatcherGoalInterface : public UInterface {
    GENERATED_BODY()
};

class IMotionMatcherGoalInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool UpdateGoal(ACharacter* Character, FFeatureVector& Goal);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool InitializeGoal(FFeatureVector& Goal);
    
};

