#include "SceneRigAkAudioEventTrackSectionData.h"

FSceneRigAkAudioEventTrackSectionData::FSceneRigAkAudioEventTrackSectionData() {
    this->Event = NULL;
    this->RetriggerEvent = false;
    this->StopAtSectionEnd = false;
    this->MaxSourceDuration = 0.00f;
}

