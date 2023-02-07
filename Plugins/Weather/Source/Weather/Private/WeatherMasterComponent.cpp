#include "WeatherMasterComponent.h"

class AActor;
class UObject;
class USceneComponent;
class UWeatherMasterComponent;

void UWeatherMasterComponent::WeatherFXRemoveFromExtraSwaps(AActor* Actor) {
}

void UWeatherMasterComponent::WeatherFXIsInExtraSwaps(AActor* Actor, bool& bIsInList) {
}

void UWeatherMasterComponent::WeatherFXAddToExtraSwaps(AActor* Actor, float OverrideSwapDistanceMeters, bool bAlwaysSwap) {
}

void UWeatherMasterComponent::SetOverrideWeather(UObject* WorldContextObject, FName NewOverrideWeather, bool bInstantChange) {
}

void UWeatherMasterComponent::SetDefaultWeather(UObject* WorldContextObject, FName NewDefaultWeather) {
}

void UWeatherMasterComponent::PushWeatherOverride(UObject* WorldContextObject, const FWeatherOverrideStackEntry& Entry, bool& bSuccess) {
}

void UWeatherMasterComponent::PopWeatherOverride(UObject* WorldContextObject, UObject* Owner) {
}

void UWeatherMasterComponent::NextSequence() {
}

void UWeatherMasterComponent::IsSnowing(UObject* WorldContextObject, bool& bIsSnowStorm, EWeatherSurfaceStormType& SnowStormType, float& SnowIntensity, float& SnowCoverage, bool bMaskWithIndoors) {
}

void UWeatherMasterComponent::IsRaining(UObject* WorldContextObject, bool& bIsRainStorm, EWeatherSurfaceStormType& RainStormType, float& RainIntensity, float& RainCoverage, bool bMaskWithIndoors) {
}

void UWeatherMasterComponent::GetWeatherWind(UObject* WorldContextObject, FWindParametersInstant& WindParameters, bool& bHaveWeather) {
}

void UWeatherMasterComponent::GetWeatherMaster(UObject* WorldContextObject, UWeatherMasterComponent*& WeatherMaster) {
}

void UWeatherMasterComponent::GetWeatherFXRoot(UObject* WorldContextObject, USceneComponent*& FXRootComponent) {
}

void UWeatherMasterComponent::GetValidWeatherPresets(UObject* WorldContextObject, TArray<FName>& WeatherPresets) {
}

void UWeatherMasterComponent::GetOverrideWeather(UObject* WorldContextObject, FName& CurrentOverrideWeather) {
}

void UWeatherMasterComponent::GetOvercast(UObject* WorldContextObject, float& Overcast) {
}

void UWeatherMasterComponent::GetDefaultWeather(UObject* WorldContextObject, FName& CurrentDefaultWeather) {
}

void UWeatherMasterComponent::GetCurrentWeather(UObject* WorldContextObject, FName& TheCurrentWeather) {
}

UWeatherMasterComponent::UWeatherMasterComponent() {
    this->CurrentWeatherSequence = NULL;
    this->CurrentStorm = NULL;
    this->WorldDecals = NULL;
    this->CloudsBlendablePriority = 1.00f;
    this->FogBlendablePriority = 100.00f;
    this->OverrideOvercastBlendable = NULL;
    this->OvercastBlendablePriority = 999.00f;
    this->bDisableCloudsBlendable = false;
    this->bDisableFogBlendable = false;
    this->bDisableOvercastBlendable = false;
    this->FXRoot = NULL;
    this->FogBlendable = NULL;
    this->CloudsBlendable = NULL;
    this->CurrentPlayingID = 0;
    this->bWeatherIsRunning = false;
    this->CurrentSeason = ESeasonEnum::Season_Invalid;
}

