#pragma once
#include "CoreMinimal.h"
#include "ERenderSettingsIndoorsType.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "RenderSettingsCustomBlendDomainIndoorsOutdoorsCurve.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainIndoorsOutdoorsCurve : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* IndoorsOutdoorsCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERenderSettingsIndoorsType IndoorsType;
    
    URenderSettingsCustomBlendDomainIndoorsOutdoorsCurve();
};

