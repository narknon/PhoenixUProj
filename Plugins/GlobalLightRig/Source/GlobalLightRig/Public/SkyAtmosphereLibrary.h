#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ESkyAtmosphereDirectionalLight.h"
#include "GlobalLightingGenerateSunColorCurve.h"
#include "GlobalLightingSunColorParams.h"
#include "SkyAtmosphereLibrary.generated.h"

class UCurveLinearColor;
class UObject;

UCLASS(Blueprintable)
class GLOBALLIGHTRIG_API USkyAtmosphereLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USkyAtmosphereLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetSunZenithLuminance(UObject* WorldContextObject, float& Luminance, ESkyAtmosphereDirectionalLight DirectionalLight);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetSunZenithColor(UObject* WorldContextObject, FLinearColor& SunColor, ESkyAtmosphereDirectionalLight DirectionalLight);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetSunLuminanceFromDirection(UObject* WorldContextObject, FVector SunDirection, float& Luminance, ESkyAtmosphereDirectionalLight DirectionalLight);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetSunLuminance(UObject* WorldContextObject, FGlobalLightingSunColorParams Params, float SunAngle, float& Luminance, ESkyAtmosphereDirectionalLight DirectionalLight);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetSunColorFromDirection(UObject* WorldContextObject, FVector SunDirection, FLinearColor& SunColor, ESkyAtmosphereDirectionalLight DirectionalLight);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetSunColor(UObject* WorldContextObject, FGlobalLightingSunColorParams Params, float SunAngle, FLinearColor& SunColor, ESkyAtmosphereDirectionalLight DirectionalLight);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetSunBaseColor(UObject* WorldContextObject, FLinearColor& BaseSunColor, ESkyAtmosphereDirectionalLight DirectionalLight);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GenerateSunColorCurve(UObject* WorldContextObject, FGlobalLightingGenerateSunColorCurve CurveParams, UCurveLinearColor* SunColorCurve, ESkyAtmosphereDirectionalLight DirectionalLight);
    
};

