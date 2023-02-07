#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingCustomBlendableName.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FGlobalLightingCustomBlendableName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FGlobalLightingCustomBlendableName();
};

