#pragma once
#include "CoreMinimal.h"
#include "DynamicLightAdaptationModSettingsVariableBlendDomainCurveBase.h"
#include "RenderSettingsCustomBlendDomainName.h"
#include "DynamicLightAdaptationModSettingsVariableCustomBlendDomainCurve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UDynamicLightAdaptationModSettingsVariableCustomBlendDomainCurve : public UDynamicLightAdaptationModSettingsVariableBlendDomainCurveBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsCustomBlendDomainName CustomBlendDomain;
    
    UDynamicLightAdaptationModSettingsVariableCustomBlendDomainCurve();
};

