#pragma once
#include "CoreMinimal.h"
#include "EStencilValueRenderCustomDepthRule.h"
#include "StencilValueRenderCustomDepthFilter.generated.h"

USTRUCT(BlueprintType)
struct FStencilValueRenderCustomDepthFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilValueRenderCustomDepthRule Rule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExcludeFX;
    
    STENCILMANAGER_API FStencilValueRenderCustomDepthFilter();
};

