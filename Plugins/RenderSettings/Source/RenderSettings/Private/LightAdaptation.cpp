#include "LightAdaptation.h"

class ULightAdaptationComponentChildOfLight;
class ULightComponent;
class UObject;

void ULightAdaptation::LightAdaptationSetIntensity(ULightComponent* LightComponent, float Intensity) {
}

void ULightAdaptation::LightAdaptationRegisterWithIntensity(ULightComponent* LightComponent, FDynamicLightAdaptationSettings Settings, float Intensity, ULightAdaptationComponentChildOfLight*& AdaptationComponent) {
}

void ULightAdaptation::LightAdaptationRegister(ULightComponent* LightComponent, FDynamicLightAdaptationSettings Settings, ULightAdaptationComponentChildOfLight*& AdaptationComponent) {
}

void ULightAdaptation::LightAdaptationIntensityFactor(UObject* WorldContextObject, FDynamicLightAdaptationSettings Settings, float& IntensityFactor) {
}

void ULightAdaptation::LightAdaptationGetIntensity(ULightComponent* LightComponent, float& Intensity) {
}

void ULightAdaptation::LightAdaptationDeregister(ULightAdaptationComponentChildOfLight* AdaptationComponent, bool bRestoreIntensity) {
}

void ULightAdaptation::GetLightAdaptationState(UObject* WorldContextObject, FEmissiveAdaptationFinalState& State) {
}

ULightAdaptation::ULightAdaptation() {
}

