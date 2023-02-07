#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "WindEnvelopeControllerCurveBase.h"
#include "WindEnvelopeControllerInlineCurve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WIND_API UWindEnvelopeControllerInlineCurve : public UWindEnvelopeControllerCurveBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Envelope;
    
    UWindEnvelopeControllerInlineCurve();
};

