#pragma once
#include "CoreMinimal.h"
#include "PlayerCentricPostProcessingOverride.h"
#include "PlayerCentricPostProcessingOverrides.generated.h"

USTRUCT(BlueprintType)
struct FPlayerCentricPostProcessingOverrides {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPlayerCentricPostProcessingOverride> OverrideStack;
    
    RENDERSETTINGS_API FPlayerCentricPostProcessingOverrides();
};

