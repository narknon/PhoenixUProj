#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SublevelEntry.generated.h"

UCLASS(Blueprintable)
class USublevelEntry : public UObject {
    GENERATED_BODY()
public:
    USublevelEntry();
private:
    UFUNCTION(BlueprintCallable)
    void OnLevelLoadFailed();
    
    UFUNCTION(BlueprintCallable)
    void OnLevelLoaded();
    
};

