#include "UMGInputManager.h"

void AUMGInputManager::UnregisterUMGInputListener(FUMGInputListener& InputListener) {
}

void AUMGInputManager::UnregisterUMGInputAxis(FUMGInputListener& InputListener, EUMGInputAxis InputAxis) {
}

void AUMGInputManager::UnregisterUMGInputAction(FUMGInputListener& InputListener, EUMGInputAction InputAction, EInputEvent InputEvent) {
}

void AUMGInputManager::UnregisterInputAxis(EUMGInputAxis InputAxis) {
}

void AUMGInputManager::UnregisterInputAction(EUMGInputAction InputAction, EInputEvent InputEvent) {
}

void AUMGInputManager::RegisterUMGInputAxis(FUMGInputListener& InputListener, EUMGInputAxis InputAxis) {
}

void AUMGInputManager::RegisterUMGInputAction(FUMGInputListener& InputListener, EUMGInputAction InputAction, EInputEvent InputEvent) {
}

void AUMGInputManager::RegisterInputAxis(EUMGInputAxis InputAxis) {
}

void AUMGInputManager::RegisterInputAction(EUMGInputAction InputAction, EInputEvent InputEvent) {
}

void AUMGInputManager::OnInputAxis(EUMGInputAxis InputAxis, const float AxisValue) {
}

void AUMGInputManager::OnInputAction(EUMGInputAction InputAction, EInputEvent InputEvent) {
}

FString AUMGInputManager::GetInputAxisEnumValueAsString(EUMGInputAxis InputAxis) {
    return TEXT("");
}

FString AUMGInputManager::GetInputActionEnumValueAsString(EUMGInputAction InputAction) {
    return TEXT("");
}

void AUMGInputManager::CreateInputAxisBinding(EUMGInputAxis InputAxis) {
}

void AUMGInputManager::CreateInputActionBinding(EUMGInputAction InputAction, EInputEvent InputEvent) {
}

AUMGInputManager::AUMGInputManager() {
    this->ReferenceUMGInputAction = EUMGInputAction::UMGConfirm;
    this->ReferenceUMGInputAxis = EUMGInputAxis::UMGMapZoomIn;
}

