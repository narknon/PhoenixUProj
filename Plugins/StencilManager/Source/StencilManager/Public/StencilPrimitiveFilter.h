#pragma once
#include "CoreMinimal.h"
#include "EStencilFilterPrimitiveMatchMode.h"
#include "EStencilRule.h"
#include "StencilPrimitiveFilter.generated.h"

USTRUCT(BlueprintType)
struct FStencilPrimitiveFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Primitives;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilRule Rule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilFilterPrimitiveMatchMode MatchMode;
    
    STENCILMANAGER_API FStencilPrimitiveFilter();
};

