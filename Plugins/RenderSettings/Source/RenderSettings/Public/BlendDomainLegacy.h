#pragma once
#include "CoreMinimal.h"
#include "BlendDomainIndoorsOutdoorsCurve.h"
#include "BlendDomainNormalizedTimeCurve.h"
#include "EBlendDomainDayNight.h"
#include "EBlendDomainIndoorsOutdoors.h"
#include "EBlendDomainLightingMode.h"
#include "EBlendDomainOvercast.h"
#include "ERenderSettingsIndoorsType.h"
#include "BlendDomainLegacy.generated.h"

USTRUCT(BlueprintType)
struct FBlendDomainLegacy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBlendDomainIndoorsOutdoors IndoorsOutdoorsBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERenderSettingsIndoorsType IndoorsType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBlendDomainDayNight DayNightBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBlendDomainOvercast OvercastClearBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBlendDomainLightingMode LightingMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomainNormalizedTimeCurve NormalizedTimeBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomainIndoorsOutdoorsCurve IndoorsOutdoorsBlendCurve;
    
    RENDERSETTINGS_API FBlendDomainLegacy();
};

