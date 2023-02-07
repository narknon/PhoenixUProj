#pragma once
#include "CoreMinimal.h"
#include "DynamicLightAdaptationModSettingsVariableBlendDomainCurveBase.h"
#include "DynamicLightAdaptationModSettingsVariableRawBlendDomainCurve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UDynamicLightAdaptationModSettingsVariableRawBlendDomainCurve : public UDynamicLightAdaptationModSettingsVariableBlendDomainCurveBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BlendDomain;
    
    UDynamicLightAdaptationModSettingsVariableRawBlendDomainCurve();
};

