#pragma once
#include "CoreMinimal.h"
#include "WindEnvelopeControllerCurveBase.h"
#include "WindEnvelopeControllerCurve.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WIND_API UWindEnvelopeControllerCurve : public UWindEnvelopeControllerCurveBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Envelope;
    
    UWindEnvelopeControllerCurve();
};

