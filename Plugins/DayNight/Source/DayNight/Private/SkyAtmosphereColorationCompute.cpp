#include "SkyAtmosphereColorationCompute.h"

class UObject;
class UPrimitiveComponent;

void USkyAtmosphereColorationCompute::SkySunInfo(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, FDayNightLightSkyAtmosphereComputeDirLight& SunInfo) {
}

void USkyAtmosphereColorationCompute::SkyMoonInfo(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, FDayNightLightSkyAtmosphereComputeDirLight& MoonInfo) {
}

void USkyAtmosphereColorationCompute::SkyDirectionalInfo(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, FDayNightLightSkyAtmosphereComputeDirLight& DirectionalLightInfo) {
}

void USkyAtmosphereColorationCompute::SkyColorsLitPacked(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, const TArray<FVector>& Directions, TArray<FLinearColor>& SkyColorsRGBIntensityAs) {
}

void USkyAtmosphereColorationCompute::SkyColorsLitCompute(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, const TArray<FVector>& Directions, TArray<FLinearColor>& SkyColors, ESkyAtmosphereColorationComputeType ComputeType, ESkyAtmosphereColorationComputeOutput OutputType) {
}

void USkyAtmosphereColorationCompute::SkyColorsLitComposited(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, const TArray<FVector>& Directions, TArray<FLinearColor>& SkyColors) {
}

void USkyAtmosphereColorationCompute::SkyColorsLit(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, const TArray<FVector>& Directions, TArray<FLinearColor>& SkyColors, TArray<float>& SkyIntensites) {
}

void USkyAtmosphereColorationCompute::SkyColorSamplingDirection(FDayNightLightSkyAtmosphereComputeSampleDirectionParams DirectionParams, FVector Direction, FVector& SamplingDirection) {
}

void USkyAtmosphereColorationCompute::SkyColorLitCompute(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, FVector Direction, FLinearColor& SkyColor, ESkyAtmosphereColorationComputeType ComputeType, ESkyAtmosphereColorationComputeOutput OutputType) {
}

void USkyAtmosphereColorationCompute::SkyColorLit(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, FVector Direction, FLinearColor& SkyColor, float& SkyIntensity) {
}

void USkyAtmosphereColorationCompute::SkyColorBase(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, FVector Direction, FLinearColor& SkyColor) {
}

void USkyAtmosphereColorationCompute::SetupDebugPrimitive(UPrimitiveComponent* Component, bool bIsSelectable, bool bShowInReflections) {
}

USkyAtmosphereColorationCompute::USkyAtmosphereColorationCompute() {
}

