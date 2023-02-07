#pragma once
#include "CoreMinimal.h"
#include "DynamicLightAdaptationModSettingsVariableBase.h"
#include "DynamicLightAdaptationModSettingsVariableCurveBase.generated.h"

class UCurveFloat;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UDynamicLightAdaptationModSettingsVariableCurveBase : public UDynamicLightAdaptationModSettingsVariableBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Curve;
    
    UDynamicLightAdaptationModSettingsVariableCurveBase();
};

