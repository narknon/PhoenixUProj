#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsEmissiveAdapatationVolumeBase.h"
#include "RenderSettingsEmissiveAdaptation.h"
#include "RenderSettingsEmissiveAdapatationVolume.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API ARenderSettingsEmissiveAdapatationVolume : public ARenderSettingsEmissiveAdapatationVolumeBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsEmissiveAdaptation EmissiveAdaptation;
    
    ARenderSettingsEmissiveAdapatationVolume();
};

