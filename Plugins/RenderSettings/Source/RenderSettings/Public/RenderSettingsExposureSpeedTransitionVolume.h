#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPostProcessingVolume.h"
#include "RenderSettingsExposureSpeedTransitionVolume.generated.h"

class UCurveFloat;

UCLASS(Blueprintable)
class RENDERSETTINGS_API ARenderSettingsExposureSpeedTransitionVolume : public ARenderSettingsPostProcessingVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* BlendCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedDown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseFilteredIndoors: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_SpeedUp: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_SpeedDown: 1;
    
    ARenderSettingsExposureSpeedTransitionVolume();
};

