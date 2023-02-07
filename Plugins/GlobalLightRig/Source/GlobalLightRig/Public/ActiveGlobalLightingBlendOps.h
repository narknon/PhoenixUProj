#pragma once
#include "CoreMinimal.h"
#include "ActiveGlobalLightingBlendOps.generated.h"

USTRUCT(BlueprintType)
struct FActiveGlobalLightingBlendOps {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BlendOps;
    
    GLOBALLIGHTRIG_API FActiveGlobalLightingBlendOps();
};

