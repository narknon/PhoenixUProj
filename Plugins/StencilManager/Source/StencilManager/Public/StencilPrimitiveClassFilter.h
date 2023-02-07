#pragma once
#include "CoreMinimal.h"
#include "EStencilRule.h"
#include "StencilPrimitiveClassFilter.generated.h"

class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct STENCILMANAGER_API FStencilPrimitiveClassFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<UPrimitiveComponent>> PrimitiveClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilRule Rule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeSubclasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName IgnoreTag;
    
    FStencilPrimitiveClassFilter();
};

