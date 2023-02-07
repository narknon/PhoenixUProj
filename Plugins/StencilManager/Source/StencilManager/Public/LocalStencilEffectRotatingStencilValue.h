#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffectRotatingStencilValue.generated.h"

USTRUCT(BlueprintType)
struct STENCILMANAGER_API FLocalStencilEffectRotatingStencilValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StencilValueMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StencilValueMax;
    
    FLocalStencilEffectRotatingStencilValue();
};

