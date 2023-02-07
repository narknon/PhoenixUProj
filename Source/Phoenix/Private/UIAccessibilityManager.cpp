#include "UIAccessibilityManager.h"

class AActor;
class UCanvasPanel;
class UUIAccessibilityAudioCueWidget;

void UUIAccessibilityManager::TriggerAccessibilityEventLeave(EAccessibilityAudioCueEventType EventType, AActor* EventActor) {
}

void UUIAccessibilityManager::TriggerAccessibilityEventEnter(EAccessibilityAudioCueEventType EventType, AActor* EventActor) {
}

void UUIAccessibilityManager::TriggerAccessibilityEventDamage(AActor* EventActor, FVector Location, float Angle, float Damage) {
}

void UUIAccessibilityManager::TriggerAccessibilityEvent(EAccessibilityAudioCueEventType EventType, AActor* EventActor) {
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

