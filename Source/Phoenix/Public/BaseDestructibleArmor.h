#pragma once
#include "CoreMinimal.h"
#include "PhoenixBudgetedActor.h"
#include "BaseDestructibleArmor.generated.h"

class AActor;

UCLASS(Blueprintable)
class ABaseDestructibleArmor : public APhoenixBudgetedActor {
    GENERATED_BODY()
public:
    ABaseDestructibleArmor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void HandlePeeves(AActor* Other);
    
};

