#pragma once
#include "CoreMinimal.h"
#include "CreatureGrowthHandler.h"
#include "CreatureHatchHandler.generated.h"

UCLASS(Blueprintable)
class ACreatureHatchHandler : public ACreatureGrowthHandler {
    GENERATED_BODY()
public:
    ACreatureHatchHandler(const FObjectInitializer& ObjectInitializer);
};

