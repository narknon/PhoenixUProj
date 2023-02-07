#include "UIAccessibilityManager.h"

class AActor;
class UCanvasPanel;
class UUIAccessibilityAudioCueWidget;

void UUIAccessibilityManager::TriggerAccessibilityEventLeave(TEnumAsByte<EAccessibilityAudioCueEventType> EventType, AActor* EventActor) {
}

void UUIAccessibilityManager::TriggerAccessibilityEventEnter(TEnumAsByte<EAccessibilityAudioCueEventType> EventType, AActor* EventActor) {
}

void UUIAccessibilityManager::TriggerAccessibilityEventDamage(AActor* EventActor, FVector Location, float Angle, float Damage) {
}

void UUIAccessibilityManager::TriggerAccessibilityEvent(TEnumAsByte<EAccessibilityAudioCueEventType> EventType, AActor* EventActor) {
}

void UUIAccessibilityManager::DeactivateAudioCues() {
}

void UUIAccessibilityManager::ActivateAudioCues(UCanvasPanel* pPanel, UUIAccessibilityAudioCueWidget* pWidget) {
}

UUIAccessibilityManager::UUIAccessibilityManager() {
    this->AudioCueDataTable = NULL;
    this->IconRenderWidgetClass = NULL;
    this->IconRenderWidgetSimpleMaterial = NULL;
}

