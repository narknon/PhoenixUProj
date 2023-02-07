#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UIDManager.generated.h"

class AActor;

UCLASS(Blueprintable)
class UUIDManager : public UObject {
    GENERATED_BODY()
public:
    UUIDManager();
protected:
    UFUNCTION(BlueprintCallable)
    void OnActorDestroyed(AActor* DestroyedActor);
    
};

