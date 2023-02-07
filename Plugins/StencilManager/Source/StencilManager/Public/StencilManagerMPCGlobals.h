#pragma once
#include "CoreMinimal.h"
#include "StencilManagerMPCGlobals.generated.h"

USTRUCT(BlueprintType)
struct FStencilManagerMPCGlobals {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GlobalBrightnessMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OutdoorsDaytimeBoost_DEPRICATED;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayerNearFadeDisable;
    
    STENCILMANAGER_API FStencilManagerMPCGlobals();
};

