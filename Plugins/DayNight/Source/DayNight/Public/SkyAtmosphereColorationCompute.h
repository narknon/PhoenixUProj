#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DayNightLightSkyAtmosphereComputeDirLight.h"
#include "DayNightLightSkyAtmosphereComputeParams.h"
#include "DayNightLightSkyAtmosphereComputeSampleDirectionParams.h"
#include "ESkyAtmosphereColorationComputeOutput.h"
#include "ESkyAtmosphereColorationComputeType.h"
#include "SkyAtmosphereColorationCompute.generated.h"

class UObject;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class DAYNIGHT_API USkyAtmosphereColorationCompute : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USkyAtmosphereColorationCompute();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void SkySunInfo(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, FDayNightLightSkyAtmosphereComputeDirLight& SunInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void SkyMoonInfo(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, FDayNightLightSkyAtmosphereComputeDirLight& MoonInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void SkyDirectionalInfo(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, FDayNightLightSkyAtmosphereComputeDirLight& DirectionalLightInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void SkyColorsLitPacked(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, const TArray<FVector>& Directions, TArray<FLinearColor>& SkyColorsRGBIntensityAs);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void SkyColorsLitCompute(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, const TArray<FVector>& Directions, TArray<FLinearColor>& SkyColors, ESkyAtmosphereColorationComputeType ComputeType, ESkyAtmosphereColorationComputeOutput OutputType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void SkyColorsLitComposited(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, const TArray<FVector>& Directions, TArray<FLinearColor>& SkyColors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void SkyColorsLit(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, const TArray<FVector>& Directions, TArray<FLinearColor>& SkyColors, TArray<float>& SkyIntensites);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void SkyColorSamplingDirection(FDayNightLightSkyAtmosphereComputeSampleDirectionParams DirectionParams, FVector Direction, FVector& SamplingDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void SkyColorLitCompute(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, FVector Direction, FLinearColor& SkyColor, ESkyAtmosphereColorationComputeType ComputeType, ESkyAtmosphereColorationComputeOutput OutputType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void SkyColorLit(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, FVector Direction, FLinearColor& SkyColor, float& SkyIntensity);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void SkyColorBase(UObject* WorldContextObject, FDayNightLightSkyAtmosphereComputeParams Params, FVector Direction, FLinearColor& SkyColor);
    
    UFUNCTION(BlueprintCallable)
    static void SetupDebugPrimitive(UPrimitiveComponent* Component, bool bIsSelectable, bool bShowInReflections);
    
};

