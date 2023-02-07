#include "AnimatedLightsAPI.h"

class ULightComponent;

bool UAnimatedLightsAPI::SetAnimatedLightIntensity(ULightComponent* Light, float Intensity, bool bSetEvenIfNotAnimated) {
    return false;
}

bool UAnimatedLightsAPI::SetAnimatedLightColorIntensity(ULightComponent* Light, FLinearColor Color, float Intensity, bool bSetEvenIfNotAnimated) {
    return false;
}

bool UAnimatedLightsAPI::SetAnimatedLightColor(ULightComponent* Light, FLinearColor Color, bool bSetEvenIfNotAnimated) {
    return false;
}

void UAnimatedLightsAPI::IsAnimatedLight(ULightComponent* Light, bool& bIsAnimatedLight) {
}

bool UAnimatedLightsAPI::GetAnimatedLightIntensity(ULightComponent* Light, float& Intensity, bool bGetEvenIfNotAnimated) {
    return false;
}

bool UAnimatedLightsAPI::GetAnimatedLightColorIntensity(ULightComponent* Light, FLinearColor& Color, float& Intensity, bool bGetEvenIfNotAnimated) {
    return false;
}

bool UAnimatedLightsAPI::GetAnimatedLightColor(ULightComponent* Light, FLinearColor& Color, bool bGetEvenIfNotAnimated) {
    return false;
}

UAnimatedLightsAPI::UAnimatedLightsAPI() {
}

