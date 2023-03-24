#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CrumblePiecesManager.generated.h"

UCLASS(Blueprintable)
class ACrumblePiecesManager : public AActor {
    GENERATED_BODY()
public:
    ACrumblePiecesManager(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    void TryToRepairAll(AActor* TargetActor);
    
};

