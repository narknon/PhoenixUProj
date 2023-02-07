#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DayNightExpHeightFogAdjustments.generated.h"

class ULightSettingsModCurve;

UCLASS(Blueprintable)
class DAYNIGHT_API UDayNightExpHeightFogAdjustments : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULightSettingsModCurve*> AltitudeMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULightSettingsModCurve*> NormalizedTimeMods;
    
    UDayNightExpHeightFogAdjustments();
};

