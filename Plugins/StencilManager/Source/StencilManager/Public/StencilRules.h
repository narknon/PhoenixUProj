#pragma once
#include "CoreMinimal.h"
#include "StencilPrimitiveClassFilter.h"
#include "StencilPrimitiveFilter.h"
#include "StencilPrimitiveTagRules.h"
#include "StencilPrimitiveTypeRules.h"
#include "StencilRules.generated.h"

USTRUCT(BlueprintType)
struct STENCILMANAGER_API FStencilRules {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilPrimitiveTagRules TagFilter;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilPrimitiveTypeRules TypeFilter;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilPrimitiveFilter PrimitiveFilter;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilPrimitiveClassFilter PrimitiveClassFilter;
    
    FStencilRules();
};

