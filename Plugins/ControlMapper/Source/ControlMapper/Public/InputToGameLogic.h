#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InputToGameLogic.generated.h"

UCLASS(Blueprintable)
class CONTROLMAPPER_API UInputToGameLogic : public UObject {
    GENERATED_BODY()
public:
    UInputToGameLogic();
    UFUNCTION(BlueprintCallable)
    void InputFlushed();
    
};

