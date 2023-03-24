#pragma once
#include "CoreMinimal.h"
#include "CreatureGrowthHandler.h"
#include "CreatureGrowUpHandler.generated.h"

UCLASS(Blueprintable)
class ACreatureGrowUpHandler : public ACreatureGrowthHandler {
    GENERATED_BODY()
public:
    ACreatureGrowUpHandler(const FObjectInitializer& ObjectInitializer);
};

