#pragma once
#include "CoreMinimal.h"
#include "Engine/Scene.h"
#include "SanctuaryIdentityDayNightSettings.h"
#include "SanctuaryIdentityGlobalLightingSettings.h"
#include "SanctuaryIdentityRenderSettings.h"
#include "SanctuaryIdentitySettings.generated.h"

USTRUCT(BlueprintType)
struct FSanctuaryIdentitySettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSanctuaryIdentityDayNightSettings DayNightSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSanctuaryIdentityGlobalLightingSettings GlobalLightingSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSanctuaryIdentityRenderSettings RenderSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostProcessSettings PostProcessSettings;
    
    PHOENIX_API FSanctuaryIdentitySettings();
};

