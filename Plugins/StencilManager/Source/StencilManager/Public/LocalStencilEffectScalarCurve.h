#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffectMaterialParameter.h"
#include "LocalStencilEffectScalarCurve.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct FLocalStencilEffectScalarCurve : public FLocalStencilEffectMaterialParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Curve;
    
    STENCILMANAGER_API FLocalStencilEffectScalarCurve();
};

