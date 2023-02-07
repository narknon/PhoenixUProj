#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffectMaterialParameter.h"
#include "LocalStencilEffectColorCurve.generated.h"

class UCurveLinearColor;

USTRUCT(BlueprintType)
struct FLocalStencilEffectColorCurve : public FLocalStencilEffectMaterialParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveLinearColor* Curve;
    
    STENCILMANAGER_API FLocalStencilEffectColorCurve();
};

