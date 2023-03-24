#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtras.h"
#include "RenderSettingsEmissiveAdapatationVolumeBase.h"
#include "RenderSettingsEmissiveAdapatationExtrasVolume.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API ARenderSettingsEmissiveAdapatationExtrasVolume : public ARenderSettingsEmissiveAdapatationVolumeBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressionsExtras EmissiveAdaptationExtras;
    
    ARenderSettingsEmissiveAdapatationExtrasVolume(const FObjectInitializer& ObjectInitializer);
};

