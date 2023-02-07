#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SpinnerInterface.generated.h"

UINTERFACE(Blueprintable)
class USpinnerInterface : public UInterface {
    GENERATED_BODY()
};

class ISpinnerInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float LoadingComplete();
    
};

