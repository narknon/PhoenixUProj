#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "DayNightCustomBlendDomainDayNightNormalizedTimeCurve.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UDayNightCustomBlendDomainDayNightNormalizedTimeCurve : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* NormalizedTimeCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMirrorAroundNoon;
    
    UDayNightCustomBlendDomainDayNightNormalizedTimeCurve();
};

