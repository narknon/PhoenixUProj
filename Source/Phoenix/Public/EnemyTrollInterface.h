#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ETrollSwingDirection.h"
#include "EnemyTrollInterface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UEnemyTrollInterface : public UInterface {
    GENERATED_BODY()
};

class IEnemyTrollInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTrollSwingDirection(ETrollSwingDirection TrollSwingDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    ETrollSwingDirection GetTrollSwingDirection() const;
    
};

