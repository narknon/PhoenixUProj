#pragma once
#include "CoreMinimal.h"
#include "CreatureGrowthHandler.h"
#include "CreatureGiveBirthHandler.generated.h"

UCLASS(Blueprintable)
class ACreatureGiveBirthHandler : public ACreatureGrowthHandler {
    GENERATED_BODY()
public:
    ACreatureGiveBirthHandler();
};

