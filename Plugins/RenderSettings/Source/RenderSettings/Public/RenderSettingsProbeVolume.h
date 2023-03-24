#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPPProbesName.h"
#include "RenderSettingsPPProbesToneMapping.h"
#include "RenderSettingsPostProcessingVolume.h"
#include "RenderSettingsProbeVolume.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API ARenderSettingsProbeVolume : public ARenderSettingsPostProcessingVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsPPProbesName Probes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsPPProbesToneMapping ToneMappingOverride;
    
    ARenderSettingsProbeVolume(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void EditProbes();
    
};

