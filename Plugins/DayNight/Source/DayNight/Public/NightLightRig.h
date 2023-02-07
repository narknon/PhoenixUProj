#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DayNightLightRigOverride.h"
#include "NightLightRig.generated.h"

class ULightSettingsLerpControl;
class ULightSettingsModCurve;

UCLASS(Blueprintable)
class DAYNIGHT_API UNightLightRig : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDayNightLightRigOverride NewMoon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDayNightLightRigOverride FullMoon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULightSettingsLerpControl*> PhaseLerp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULightSettingsModCurve*> AltitudeMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULightSettingsModCurve*> SunAltitudeMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULightSettingsModCurve*> SunTimeMods;
    
    UNightLightRig();
};

