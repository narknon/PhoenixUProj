#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Acknowledgement.generated.h"

UCLASS(Blueprintable)
class UAcknowledgement : public UObject {
    GENERATED_BODY()
public:
    UAcknowledgement();
    UFUNCTION(BlueprintCallable)
    void EventExecute(bool bNewResult);
    
};

