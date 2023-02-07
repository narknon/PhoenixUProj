#pragma once
#include "CoreMinimal.h"
#include "WindEnvelopeController.h"
#include "WindEnvelopeControllerCurveBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWindEnvelopeControllerCurveBase : public UWindEnvelopeController {
    GENERATED_BODY()
public:
    UWindEnvelopeControllerCurveBase();
};

