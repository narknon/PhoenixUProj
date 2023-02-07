#include "SkyAtmosphereLibrary.h"

class UCurveLinearColor;
class UObject;

bool USkyAtmosphereLibrary::GetSunZenithLuminance(UObject* WorldContextObject, float& Luminance, ESkyAtmosphereDirectionalLight DirectionalLight) {
    return false;
}

bool USkyAtmosphereLibrary::GetSunZenithColor(UObject* WorldContextObject, FLinearColor& SunColor, ESkyAtmosphereDirectionalLight DirectionalLight) {
    return false;
}

bool USkyAtmosphereLibrary::GetSunLuminanceFromDirection(UObject* WorldContextObject, FVector SunDirection, float& Luminance, ESkyAtmosphereDirectionalLight DirectionalLight) {
    return false;
}

bool USkyAtmosphereLibrary::GetSunLuminance(UObject* WorldContextObject, FGlobalLightingSunColorParams Params, float SunAngle, float& Luminance, ESkyAtmosphereDirectionalLight DirectionalLight) {
    return false;
}

bool USkyAtmosphereLibrary::GetSunColorFromDirection(UObject* WorldContextObject, FVector SunDirection, FLinearColor& SunColor, ESkyAtmosphereDirectionalLight DirectionalLight) {
    return false;
}

bool USkyAtmosphereLibrary::GetSunColor(UObject* WorldContextObject, FGlobalLightingSunColorParams Params, float SunAngle, FLinearColor& SunColor, ESkyAtmosphereDirectionalLight DirectionalLight) {
    return false;
}

bool USkyAtmosphereLibrary::GetSunBaseColor(UObject* WorldContextObject, FLinearColor& BaseSunColor, ESkyAtmosphereDirectionalLight DirectionalLight) {
    return false;
}

bool USkyAtmosphereLibrary::GenerateSunColorCurve(UObject* WorldContextObject, FGlobalLightingGenerateSunColorCurve CurveParams, UCurveLinearColor* SunColorCurve, ESkyAtmosphereDirectionalLight DirectionalLight) {
    return false;
}

USkyAtmosphereLibrary::USkyAtmosphereLibrary() {
}

