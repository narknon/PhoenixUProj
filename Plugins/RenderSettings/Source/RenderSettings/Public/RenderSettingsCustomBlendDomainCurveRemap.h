#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "RenderSettingsCustomBlendDomainCurveRemap.generated.h"

class UCurveFloat;
class URenderSettingsCustomBlendDomain;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainCurveRemap : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URenderSettingsCustomBlendDomain* domain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Curve;
    
    URenderSettingsCustomBlendDomainCurveRemap();
};

