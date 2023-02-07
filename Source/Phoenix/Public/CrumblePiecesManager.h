#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CrumblePiecesManager.generated.h"

UCLASS(Blueprintable)
class ACrumblePiecesManager : public AActor {
    GENERATED_BODY()
public:
    ACrumblePiecesManager();
protected:
    UFUNCTION(BlueprintCallable)
    void TryToRepairAll(AActor* TargetActor);
    
};

