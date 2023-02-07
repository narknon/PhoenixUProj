#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AmbientCreatureSpawnManager.generated.h"

class UAmbientCreatureSpawnManager;

UCLASS(Blueprintable, Config=Game)
class UAmbientCreatureSpawnManager : public UObject {
    GENERATED_BODY()
public:
    UAmbientCreatureSpawnManager();
    UFUNCTION(BlueprintCallable)
    void SetSpawningEnabled(bool bEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UAmbientCreatureSpawnManager* Get();
    
    UFUNCTION(BlueprintCallable)
    void CullAllCreatures(bool bFadeOut);
    
};

