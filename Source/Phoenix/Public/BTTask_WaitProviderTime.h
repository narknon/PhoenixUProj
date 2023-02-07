#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "BehaviorTree/Tasks/BTTask_Wait.h"
#include "BTTask_WaitProviderTime.generated.h"

UCLASS(Blueprintable)
class UBTTask_WaitProviderTime : public UBTTask_Wait {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue ParameterizedWaitTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Deviation;
    
public:
    UBTTask_WaitProviderTime();
};

