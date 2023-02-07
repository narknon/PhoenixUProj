#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "RenderSettingsCustomBlendDomainPreset.generated.h"

class URenderSettingsCustomBlendDomainPresetAsset;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainPreset : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsCustomBlendDomainPresetAsset* Preset;
    
    URenderSettingsCustomBlendDomainPreset();
};

