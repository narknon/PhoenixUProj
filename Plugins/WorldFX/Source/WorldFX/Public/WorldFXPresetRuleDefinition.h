#pragma once
#include "CoreMinimal.h"
#include "WorldFXPresetRuleDefinition.generated.h"

class UWorldFXRule;

USTRUCT(BlueprintType)
struct FWorldFXPresetRuleDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWorldFXRule* Rule;
    
    WORLDFX_API FWorldFXPresetRuleDefinition();
};

