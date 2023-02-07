#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapObjectTagRules.h"
#include "MaterialSwapMeshTagRules.generated.h"

USTRUCT(BlueprintType)
struct FMaterialSwapMeshTagRules : public FMaterialSwapObjectTagRules {
    GENERATED_BODY()
public:
    MATERIALPERMUTER_API FMaterialSwapMeshTagRules();
};

