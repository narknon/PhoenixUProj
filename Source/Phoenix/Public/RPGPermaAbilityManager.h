#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RPGPermaAbilityManager.generated.h"

UCLASS(Blueprintable)
class URPGPermaAbilityManager : public UObject {
    GENERATED_BODY()
public:
    URPGPermaAbilityManager();
private:
    UFUNCTION(BlueprintCallable)
    void OnGameToBeLoaded();
    
public:
    UFUNCTION(BlueprintCallable)
    void AddPermaAbilitiesToPlayer();
    
};

