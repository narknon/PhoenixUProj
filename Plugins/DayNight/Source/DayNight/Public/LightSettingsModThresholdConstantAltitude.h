#pragma once
#include "CoreMinimal.h"
#include "LightSettingsModThreshold.h"
#include "LightSettingsModThresholdConstantAltitude.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsModThresholdConstantAltitude : public ULightSettingsModThreshold {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AltitudeThreshold;
    
    ULightSettingsModThresholdConstantAltitude();
};

