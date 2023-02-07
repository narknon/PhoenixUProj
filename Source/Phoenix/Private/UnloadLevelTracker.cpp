#include "UnloadLevelTracker.h"

void UUnloadLevelTracker::OnLevelUnloaded() {
}

void UUnloadLevelTracker::Cleanup() {
}

UUnloadLevelTracker::UUnloadLevelTracker() {
    this->World = NULL;
    this->StreamingLevel = NULL;
    this->Manager = NULL;
}

