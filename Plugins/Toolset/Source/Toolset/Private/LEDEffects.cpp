#include "LEDEffects.h"

void ULEDEffects::SetColor(const int32& ControllerId, const FColor& Color) {
}

void ULEDEffects::ResetLED(const int32& ControllerId) {
}

void ULEDEffects::ResetAll() {
}

bool ULEDEffects::GetActiveColor(FColor& Color) {
    return false;
}

ULEDEffects::ULEDEffects() {
    this->BaseLEDFadeEffect = NULL;
}

