#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LoadComplete.generated.h"

UCLASS(Blueprintable)
class ULoadComplete : public UObject {
    GENERATED_BODY()
public:
    ULoadComplete();
    UFUNCTION(BlueprintCallable)
    void OnLoadCompleteCallback();
    
};

