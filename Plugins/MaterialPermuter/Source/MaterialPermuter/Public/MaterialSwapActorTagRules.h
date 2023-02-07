#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapObjectTagRules.h"
#include "MaterialSwapActorTagRules.generated.h"

USTRUCT(BlueprintType)
struct FMaterialSwapActorTagRules : public FMaterialSwapObjectTagRules {
    GENERATED_BODY()
public:
    MATERIALPERMUTER_API FMaterialSwapActorTagRules();
};

