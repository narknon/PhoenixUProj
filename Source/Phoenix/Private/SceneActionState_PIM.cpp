#include "SceneActionState_PIM.h"

class USceneRigInputScreen;
class UUserWidget;

void USceneActionState_PIM::WidgetLoaded(TSoftClassPtr<USceneRigInputScreen> WidgetClassPtr) {
}

void USceneActionState_PIM::TelescopeWidgetLoaded(TSoftClassPtr<UUserWidget> WidgetClassPtr) {
}

void USceneActionState_PIM::HandleWildcardAxisChanged(float AxisVal) {
}

void USceneActionState_PIM::HandleWildcardActionReleased() {
}

void USceneActionState_PIM::HandleWildcardActionPressed() {
}

void USceneActionState_PIM::HandleSpellButtonPressed(ESpellButton SpellButton) {
}

void USceneActionState_PIM::HandleModifierReleased() {
}

void USceneActionState_PIM::HandleModifierPressed() {
}

void USceneActionState_PIM::HandleModifierAxisChanged(float AxisVal) {
}

void USceneActionState_PIM::HandleAnalogStick(FKey Key, float AnalogValue) {
}

void USceneActionState_PIM::HandleAcceptActionReleased() {
}

void USceneActionState_PIM::HandleAcceptActionPressed() {
}

void USceneActionState_PIM::FinishNow(const bool bSuccess) {
}

USceneActionState_PIM::USceneActionState_PIM() {
    this->CustomFocusBlendable = NULL;
}

