#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RenderSettingsPPExposure.h"
#include "RenderSettingsPPExposureSettings.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API URenderSettingsPPExposureSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRenderSettingsPPExposure> Settings;
    
    URenderSettingsPPExposureSettings();
};

