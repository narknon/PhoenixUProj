#include "SCT_StreamingEventWrapper.h"

void USCT_StreamingEventWrapper::OnLevelUnloaded() {
}

void USCT_StreamingEventWrapper::OnLevelShown() {
}

void USCT_StreamingEventWrapper::OnLevelLoaded() {
}

void USCT_StreamingEventWrapper::OnLevelHidden() {
}

USCT_StreamingEventWrapper::USCT_StreamingEventWrapper() {
    this->LevelController = NULL;
    this->LevelStreaming = NULL;
}

