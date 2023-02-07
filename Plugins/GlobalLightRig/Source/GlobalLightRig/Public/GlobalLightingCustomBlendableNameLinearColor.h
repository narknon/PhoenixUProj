#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingCustomBlendableName.h"
#include "GlobalLightingCustomBlendableNameLinearColor.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FGlobalLightingCustomBlendableNameLinearColor : public FGlobalLightingCustomBlendableName {
    GENERATED_BODY()
public:
    FGlobalLightingCustomBlendableNameLinearColor();
};

