#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffectMaterialParameter.h"
#include "LocalStencilEffectScalar.generated.h"

USTRUCT(BlueprintType)
struct FLocalStencilEffectScalar : public FLocalStencilEffectMaterialParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    STENCILMANAGER_API FLocalStencilEffectScalar();
};

