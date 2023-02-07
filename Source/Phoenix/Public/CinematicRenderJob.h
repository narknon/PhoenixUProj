#pragma once
#include "CoreMinimal.h"
#include "TimeInput.h"
#include "WeatherDefinitionName.h"
#include "CinematicAvatarSettings.h"
#include "Templates/SubclassOf.h"
#include "CinematicRenderJob.generated.h"

class UCinematicBatchHUD;

USTRUCT(BlueprintType)
struct PHOENIX_API FCinematicRenderJob {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Suffix;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCinematicAvatarSettings AvatarOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeInput TimeOfDayOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherDefinitionName WeatherOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCinematicBatchHUD> Overlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDisabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAddToShotgun;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseViewmodeUnlit;
    
    FCinematicRenderJob();
};

