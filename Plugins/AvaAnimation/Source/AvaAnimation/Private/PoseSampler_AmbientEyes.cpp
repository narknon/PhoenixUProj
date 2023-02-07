#include "PoseSampler_AmbientEyes.h"

void UPoseSampler_AmbientEyes::OnDialogueLineAnimStarted(FName DialogueID, float WorldTime) {
}

void UPoseSampler_AmbientEyes::OnDialogueLineAnimFinished(bool bCancelled) {
}

UPoseSampler_AmbientEyes::UPoseSampler_AmbientEyes() {
    this->LODThreshold = 1;
}

