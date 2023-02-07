#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "AIPerformTaskDelay.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskDelay : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    UAIPerformTaskDelay();
private:
    UFUNCTION(BlueprintCallable)
    void OnDelayFinished();
    
};

