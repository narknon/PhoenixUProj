#pragma once
#include "CoreMinimal.h"
#include "DynamicLightAdaptationModSettingsVariableBlendDomainCurveBase.h"
#include "RenderSettingsPreComputedBlendDomainName.h"
#include "DynamicLightAdaptationModSettingsVariableBlendDomainCurve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UDynamicLightAdaptationModSettingsVariableBlendDomainCurve : public UDynamicLightAdaptationModSettingsVariableBlendDomainCurveBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsPreComputedBlendDomainName BlendDomain;
    
    UDynamicLightAdaptationModSettingsVariableBlendDomainCurve();
};

