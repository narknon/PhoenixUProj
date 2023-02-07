#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffectColorCurve.h"
#include "LocalStencilEffectDelegatedActorOverrideFiltered.h"
#include "LocalStencilEffectScalarCurve.h"
#include "LocalStencilEffectDelegatedActorExtraCurveParameters.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULocalStencilEffectDelegatedActorExtraCurveParameters : public ULocalStencilEffectDelegatedActorOverrideFiltered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocalStencilEffectScalarCurve> ExtraScalarCurves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocalStencilEffectColorCurve> ExtraColorCurves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSetExtraScalarCurves: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSetExtraColorCurves: 1;
    
    ULocalStencilEffectDelegatedActorExtraCurveParameters();
};

