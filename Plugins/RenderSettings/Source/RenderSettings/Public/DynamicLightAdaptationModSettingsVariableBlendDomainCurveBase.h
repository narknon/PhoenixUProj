#pragma once
#include "CoreMinimal.h"
#include "DynamicLightAdaptationModSettingsVariableCurveBase.h"
#include "DynamicLightAdaptationModSettingsVariableBlendDomainCurveBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UDynamicLightAdaptationModSettingsVariableBlendDomainCurveBase : public UDynamicLightAdaptationModSettingsVariableCurveBase {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultValueIfMissing;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCamera;
    
    UDynamicLightAdaptationModSettingsVariableBlendDomainCurveBase();
};

