#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerLinearColor.h"
#include "FXAutoTriggerLinearColorCurve.generated.h"

class UCurveLinearColor;
class UFXAutoTriggerScalar;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UFXAutoTriggerLinearColorCurve : public UFXAutoTriggerLinearColor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveLinearColor* Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerScalar* XAxis;
    
    UFXAutoTriggerLinearColorCurve();
};

