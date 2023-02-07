#pragma once
#include "CoreMinimal.h"
#include "WorldFXPresetRuleDefinition.h"
#include "WorldFXPresets.generated.h"

USTRUCT(BlueprintType)
struct FWorldFXPresets {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorldFXPresetRuleDefinition> Presets;
    
    WORLDFX_API FWorldFXPresets();
};

