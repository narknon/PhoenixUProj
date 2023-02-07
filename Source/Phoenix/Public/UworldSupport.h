#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UworldSupport.generated.h"

class UUworldSupport;

UCLASS(Blueprintable)
class UUworldSupport : public UObject {
    GENERATED_BODY()
public:
    UUworldSupport();
    UFUNCTION(BlueprintCallable)
    static UUworldSupport* Get();
    
};

