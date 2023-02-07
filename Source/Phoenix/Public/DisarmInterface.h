#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "DisarmInterface.generated.h"

class AActor;

UINTERFACE(Blueprintable, MinimalAPI)
class UDisarmInterface : public UInterface {
    GENERATED_BODY()
};

class IDisarmInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    AActor* Disarm(AActor* Instigator, FVector HitDirection, float ScaleDisarmForce);
    
};

