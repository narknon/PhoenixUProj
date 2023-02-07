#include "AkAudioEvent.h"

float UAkAudioEvent::GetMinimumDuration() const {
    return 0.0f;
}

float UAkAudioEvent::GetMaximumDuration() const {
    return 0.0f;
}

float UAkAudioEvent::GetMaxAttenuationRadius() const {
    return 0.0f;
}

bool UAkAudioEvent::GetIsInfinite() const {
    return false;
}

UAkAudioEvent::UAkAudioEvent() {
    this->RequiredBank = NULL;
    this->CurrentLocalizedPlatformData = NULL;
    this->MaxAttenuationRadius = 0.00f;
    this->IsInfinite = false;
    this->MinimumDuration = 0.00f;
    this->MaximumDuration = 0.00f;
}

