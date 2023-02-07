#pragma once
#include "CoreMinimal.h"
#include "WorldFXPresetRuleName.generated.h"

USTRUCT(BlueprintType)
struct FWorldFXPresetRuleName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    WORLDFX_API FWorldFXPresetRuleName();
};

