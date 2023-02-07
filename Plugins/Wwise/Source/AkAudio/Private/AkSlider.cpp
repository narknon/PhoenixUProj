#include "AkSlider.h"

void UAkSlider::SetValue(float InValue) {
}

void UAkSlider::SetStepSize(float InValue) {
}

void UAkSlider::SetSliderHandleColor(FLinearColor InValue) {
}

void UAkSlider::SetSliderBarColor(FLinearColor InValue) {
}

void UAkSlider::SetLocked(bool InValue) {
}

void UAkSlider::SetIndentHandle(bool InValue) {
}

void UAkSlider::SetAkSliderItemProperty(const FString& ItemProperty) {
}

void UAkSlider::SetAkSliderItemId(const FGuid& ItemId) {
}

float UAkSlider::GetValue() const {
    return 0.0f;
}

FString UAkSlider::GetAkSliderItemProperty() const {
    return TEXT("");
}

FGuid UAkSlider::GetAkSliderItemId() const {
    return FGuid{};
}

UAkSlider::UAkSlider() {
    this->Value = 0.00f;
    this->Orientation = Orient_Horizontal;
    this->IndentHandle = false;
    this->Locked = false;
    this->StepSize = 0.01f;
    this->IsFocusable = true;
}

