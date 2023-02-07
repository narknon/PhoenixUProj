#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "DayNightCustomBlendDomainDayNightAltitudeCurveRemap.generated.h"

class UCurveFloat;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UDayNightCustomBlendDomainDayNightAltitudeCurveRemap : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* AltitudeRemapCurve;
    
    UDayNightCustomBlendDomainDayNightAltitudeCurveRemap();
};

