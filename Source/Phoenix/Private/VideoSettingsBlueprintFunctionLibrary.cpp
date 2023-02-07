#include "VideoSettingsBlueprintFunctionLibrary.h"

class UObject;

TArray<FIntPoint> UVideoSettingsBlueprintFunctionLibrary::SortResolutions(const TArray<FIntPoint>& Resolutions) {
    return TArray<FIntPoint>();
}

bool UVideoSettingsBlueprintFunctionLibrary::ShouldEnableUpscaleSharpnessSlider(EUpscaleMode UpscaleMode) {
    return false;
}

bool UVideoSettingsBlueprintFunctionLibrary::ShouldEnableUpscaleModes(EAntiAliasingMode AntiAliasingMode) {
    return false;
}

bool UVideoSettingsBlueprintFunctionLibrary::ShouldEnableRenderingResolutionsDropdown(EUpscaleMode UpscaleMode, EAntiAliasingMode AntiAliasingMode) {
    return false;
}

bool UVideoSettingsBlueprintFunctionLibrary::ShouldEnableAntiAliasingDropdown(EUpscaleMode UpscaleMode) {
    return false;
}

void UVideoSettingsBlueprintFunctionLibrary::SetCalibrationScreenMode(const UObject* WorldContextObject, bool bEnabled) {
}

bool UVideoSettingsBlueprintFunctionLibrary::IsRaytracingEnabledInEngine() {
    return false;
}

bool UVideoSettingsBlueprintFunctionLibrary::IsRayTracingAvailable() {
    return false;
}

bool UVideoSettingsBlueprintFunctionLibrary::IsRaytracedShadowsEnabledInGame() {
    return false;
}

EUpscaleMode UVideoSettingsBlueprintFunctionLibrary::IndexToUpscaleMode(int32 SelectedIdx) {
    return EUpscaleMode::None;
}

float UVideoSettingsBlueprintFunctionLibrary::GetUpscaleModePercentage(EUpscaleMode UpscaleMode, FIntPoint Resolution) {
    return 0.0f;
}

EUpscaleBrand UVideoSettingsBlueprintFunctionLibrary::GetUpscaleBrandForMode(EUpscaleMode InMode) {
    return EUpscaleBrand::None;
}

FIntPoint UVideoSettingsBlueprintFunctionLibrary::GetMinResolution() {
    return FIntPoint{};
}

FIntPoint UVideoSettingsBlueprintFunctionLibrary::GetHighestAvailableResolution() {
    return FIntPoint{};
}

bool UVideoSettingsBlueprintFunctionLibrary::GetHDRToneMapParameters(float& MinToneMapLuminance, float& MaxToneMapLuminance, float& MaxFullFrameTonemapLuminance) {
    return false;
}

bool UVideoSettingsBlueprintFunctionLibrary::GetDefaultUpscaleSharpnessIfChanged(EUpscaleMode InOldMode, EUpscaleMode InNewMode, float& OutSharpness) {
    return false;
}

TArray<EUpscaleMode> UVideoSettingsBlueprintFunctionLibrary::GetAvailableUpscaleModesForBrand(EUpscaleBrand InBrand) {
    return TArray<EUpscaleMode>();
}

TArray<EUpscaleMode> UVideoSettingsBlueprintFunctionLibrary::GetAvailableUpscaleModes() {
    return TArray<EUpscaleMode>();
}

TArray<EUpscaleBrand> UVideoSettingsBlueprintFunctionLibrary::GetAvailableUpscaleBrands() {
    return TArray<EUpscaleBrand>();
}

TArray<FIntPoint> UVideoSettingsBlueprintFunctionLibrary::GetAvailableResolutions() {
    return TArray<FIntPoint>();
}

TMap<int32, FIntPoint> UVideoSettingsBlueprintFunctionLibrary::GetAvailableRenderingResolutions(FIntPoint MonitorNativeResolution) {
    return TMap<int32, FIntPoint>();
}

TArray<float> UVideoSettingsBlueprintFunctionLibrary::GetAvailableRatios() {
    return TArray<float>();
}

TArray<FSimpleMonitorInformation> UVideoSettingsBlueprintFunctionLibrary::GetAvailableMonitors() {
    return TArray<FSimpleMonitorInformation>();
}

bool UVideoSettingsBlueprintFunctionLibrary::GetAvailableGPUs(TArray<FGraphicsAdapterDesc>& OutGPUs) {
    return false;
}

TArray<int32> UVideoSettingsBlueprintFunctionLibrary::GetAvailableFramerateLimits() {
    return TArray<int32>();
}

TArray<EAntiAliasingMode> UVideoSettingsBlueprintFunctionLibrary::GetAvailableAntiAliasingModes() {
    return TArray<EAntiAliasingMode>();
}

EUpscaleMode UVideoSettingsBlueprintFunctionLibrary::ConvertModeToEquivBrandMode(EUpscaleMode InMode, EUpscaleBrand InBrand) {
    return EUpscaleMode::None;
}

UVideoSettingsBlueprintFunctionLibrary::UVideoSettingsBlueprintFunctionLibrary() {
}

