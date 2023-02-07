#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffectMaterialParameter.generated.h"

USTRUCT(BlueprintType)
struct FLocalStencilEffectMaterialParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MaterialParameter;
    
    STENCILMANAGER_API FLocalStencilEffectMaterialParameter();
};

