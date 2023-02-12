#include "AkCheckBox.h"

void UAkCheckBox::SetIsChecked(bool InIsChecked) {
}

void UAkCheckBox::SetCheckedState(ECheckBoxState InCheckedState) {
}

void UAkCheckBox::SetAkItemId(const FGuid& ItemId) {
}

void UAkCheckBox::SetAkBoolProperty(const FString& ItemProperty) {
}

bool UAkCheckBox::IsPressed() const {
    return false;
}

bool UAkCheckBox::IsChecked() const {
    return false;
}

ECheckBoxState UAkCheckBox::GetCheckedState() const {
    return ECheckBoxState::Unchecked;
}

FString UAkCheckBox::GetAkProperty() const {
    return TEXT("");
}

FGuid UAkCheckBox::GetAkItemId() const {
    return FGuid{};
}

UAkCheckBox::UAkCheckBox() {
    this->CheckedState = ECheckBoxState::Unchecked;
    this->HorizontalAlignment = HAlign_Fill;
    this->IsFocusable = true;
}

