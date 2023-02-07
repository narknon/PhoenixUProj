#include "SubtitleSettings.h"

class UObject;

void USubtitleSettings::StartSettingAudioPrioritySuppress(int32 NewValue, EStandardManagedPriority Priority, const UObject* Requestor) {
}

void USubtitleSettings::StartSettingAudioPriorityCutoff(int32 NewValue, EStandardManagedPriority Priority, const UObject* Requestor) {
}

void USubtitleSettings::StartSettingAudioLowPriorityDistanceSuppress(float NewValue) {
}

void USubtitleSettings::StartOverrideSubtitlePosition(const UObject* Requestor, const FVector2D OverridePos) {
}

bool USubtitleSettings::GetOverrideSubtitlePositionState() {
    return false;
}

int32 USubtitleSettings::GetAudioPrioritySuppress() {
    return 0;
}

int32 USubtitleSettings::GetAudioPriorityCutoff() {
    return 0;
}

float USubtitleSettings::GetAudioLowPrioritySuppressDistance() {
    return 0.0f;
}

void USubtitleSettings::FinishSettingAudioPrioritySuppress(EStandardManagedPriority Priority, const UObject* Requestor) {
}

void USubtitleSettings::FinishSettingAudioPriorityCutoff(EStandardManagedPriority Priority, const UObject* Requestor) {
}

void USubtitleSettings::FinishSettingAudioLowPriorityDistanceSuppress() {
}

void USubtitleSettings::FinishOverrideSubtitlePosition(const UObject* Requestor) {
}

void USubtitleSettings::AddAudioPrioritySuppressChangedHandler(USubtitleSettings::FAudioPriorityChangedHandler AudioPrioritySuppressHandler) {
}

void USubtitleSettings::AddAudioPriorityCutoffChangedHandler(USubtitleSettings::FAudioPriorityChangedHandler AudioPriorityCuttoffHandler) {
}

USubtitleSettings::USubtitleSettings() {
    this->AudioPriorityCutoff = 70;
    this->AudioPrioritySuppress = 30;
    this->AudioLowPrioritySuppressDistance = 2100.00f;
}

