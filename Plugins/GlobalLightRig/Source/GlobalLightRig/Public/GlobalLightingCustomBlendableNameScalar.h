#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingCustomBlendableName.h"
#include "GlobalLightingCustomBlendableNameScalar.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FGlobalLightingCustomBlendableNameScalar : public FGlobalLightingCustomBlendableName {
    GENERATED_BODY()
public:
    FGlobalLightingCustomBlendableNameScalar();
};

