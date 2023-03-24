#pragma once
#include "CoreMinimal.h"
#include "FireOnceSpellTool.h"
#include "DeathlyHallowsDistractionSpellTool.generated.h"

UCLASS(Blueprintable)
class ADeathlyHallowsDistractionSpellTool : public AFireOnceSpellTool {
    GENERATED_BODY()
public:
    ADeathlyHallowsDistractionSpellTool(const FObjectInitializer& ObjectInitializer);
};

