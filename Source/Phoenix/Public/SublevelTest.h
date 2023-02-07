#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SublevelTest.generated.h"

UCLASS(Blueprintable)
class USublevelTest : public UObject {
    GENERATED_BODY()
public:
    USublevelTest();
    UFUNCTION(BlueprintCallable)
    void LevelUnloaded();
    
    UFUNCTION(BlueprintCallable)
    void LevelLoadFailed();
    
    UFUNCTION(BlueprintCallable)
    void LevelLoaded();
    
};

