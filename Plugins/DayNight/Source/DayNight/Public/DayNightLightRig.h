#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LightParameterSmoothingDiscontinuitySettings.h"
#include "DayNightLightRig.generated.h"

class UCurveFloat;
class UDayLightRig;
class UDayNightExpHeightFogAdjustments;
class ULightDirectionLerpControl;
class ULightParameterSmoothing;
class ULightSettingsLerpControl;
class ULightSettingsModCurve;
class UNightLightRig;

UCLASS(Blueprintable)
class DAYNIGHT_API UDayNightLightRig : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDayLightRig* Day;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNightLightRig* Night;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumDirectionalLightIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* SunAltitudeInfluenceCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* MoonAltitudeInfluenceCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULightSettingsLerpControl*> DayNightLerp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULightDirectionLerpControl* DayNightLerpDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BlendOps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULightSettingsModCurve*> SunAltitudeMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULightSettingsModCurve*> NormalizedTimeMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightParameterSmoothingDiscontinuitySettings DiscontinuitySettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULightParameterSmoothing*> SmoothingMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDayNightExpHeightFogAdjustments* ExpHeightFogAdjustments;
    
    UDayNightLightRig();
};

