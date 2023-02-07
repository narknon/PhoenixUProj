#pragma once
#include "CoreMinimal.h"
#include "StencilValueRenderCustomDepth.generated.h"

USTRUCT(BlueprintType)
struct STENCILMANAGER_API FStencilValueRenderCustomDepth {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StencilValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRenderCustomDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverridestencilValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideRenderCustomDepth;
    
    FStencilValueRenderCustomDepth();
};

