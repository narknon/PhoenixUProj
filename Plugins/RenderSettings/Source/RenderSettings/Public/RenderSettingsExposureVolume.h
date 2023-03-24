#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPPExposureName.h"
#include "RenderSettingsPostProcessingVolume.h"
#include "RenderSettingsExposureVolume.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API ARenderSettingsExposureVolume : public ARenderSettingsPostProcessingVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsPPExposureName Exposure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExposureTweak;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExposureTweak;
    
    ARenderSettingsExposureVolume(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void EditExposure();
    
};

