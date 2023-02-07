#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EAntiAliasingMode.h"
#include "EUpscaleBrand.h"
#include "EUpscaleMode.h"
#include "GraphicsAdapterDesc.h"
#include "SimpleMonitorInformation.h"
#include "VideoSettingsBlueprintFunctionLibrary.generated.h"

class UObject;

UCLASS(Blueprintable)
class PHOENIX_API UVideoSettingsBlueprintFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UVideoSettingsBlueprintFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static TArray<FIntPoint> SortResolutions(const TArray<FIntPoint>& Resolutions);
    
    UFUNCTION(BlueprintCallable)
    static bool ShouldEnableUpscaleSharpnessSlider(EUpscaleMode UpscaleMode);
    
    UFUNCTION(BlueprintCallable)
    static bool ShouldEnableUpscaleModes(EAntiAliasingMode AntiAliasingMode);
    
    UFUNCTION(BlueprintCallable)
    static bool ShouldEnableRenderingResolutionsDropdown(EUpscaleMode UpscaleMode, EAntiAliasingMode AntiAliasingMode);
    
    UFUNCTION(BlueprintCallable)
    static bool ShouldEnableAntiAliasingDropdown(EUpscaleMode UpscaleMode);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetCalibrationScreenMode(const UObject* WorldContextObject, bool bEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsRaytracingEnabledInEngine();
    
    UFUNCTION(BlueprintCallable)
    static bool IsRayTracingAvailable();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsRaytracedShadowsEnabledInGame();
    
    UFUNCTION(BlueprintCallable)
    static EUpscaleMode IndexToUpscaleMode(int32 SelectedIdx);
    
    UFUNCTION(BlueprintCallable)
    static float GetUpscaleModePercentage(EUpscaleMode UpscaleMode, FIntPoint Resolution);
    
    UFUNCTION(BlueprintCallable)
    static EUpscaleBrand GetUpscaleBrandForMode(EUpscaleMode InMode);
    
    UFUNCTION(BlueprintCallable)
    static FIntPoint GetMinResolution();
    
    UFUNCTION(BlueprintCallable)
    static FIntPoint GetHighestAvailableResolution();
    
    UFUNCTION(BlueprintCallable)
    static bool GetHDRToneMapParameters(float& MinToneMapLuminance, float& MaxToneMapLuminance, float& MaxFullFrameTonemapLuminance);
    
    UFUNCTION(BlueprintCallable)
    static bool GetDefaultUpscaleSharpnessIfChanged(EUpscaleMode InOldMode, EUpscaleMode InNewMode, float& OutSharpness);
    
    UFUNCTION(BlueprintCallable)
    static TArray<EUpscaleMode> GetAvailableUpscaleModesForBrand(EUpscaleBrand InBrand);
    
    UFUNCTION(BlueprintCallable)
    static TArray<EUpscaleMode> GetAvailableUpscaleModes();
    
    UFUNCTION(BlueprintCallable)
    static TArray<EUpscaleBrand> GetAvailableUpscaleBrands();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FIntPoint> GetAvailableResolutions();
    
    UFUNCTION(BlueprintCallable)
    static TMap<int32, FIntPoint> GetAvailableRenderingResolutions(FIntPoint MonitorNativeResolution);
    
    UFUNCTION(BlueprintCallable)
    static TArray<float> GetAvailableRatios();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FSimpleMonitorInformation> GetAvailableMonitors();
    
    UFUNCTION(BlueprintCallable)
    static bool GetAvailableGPUs(TArray<FGraphicsAdapterDesc>& OutGPUs);
    
    UFUNCTION(BlueprintCallable)
    static TArray<int32> GetAvailableFramerateLimits();
    
    UFUNCTION(BlueprintCallable)
    static TArray<EAntiAliasingMode> GetAvailableAntiAliasingModes();
    
    UFUNCTION(BlueprintCallable)
    static EUpscaleMode ConvertModeToEquivBrandMode(EUpscaleMode InMode, EUpscaleBrand InBrand);
    
};

