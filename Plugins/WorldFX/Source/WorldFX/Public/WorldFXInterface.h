#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "WorldFXSpawnOverrides.h"
#include "WorldFXInterface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UWorldFXInterface : public UInterface {
    GENERATED_BODY()
};

class IWorldFXInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void WorldFXInterfaceStop(bool bImmediately);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void WorldFXInterfaceStart(FWorldFXSpawnOverrides SpawnOverrides);
    
};

