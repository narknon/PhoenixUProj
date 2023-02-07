#include "PersistentGameData.h"

UPersistentGameData::UPersistentGameData() {
    this->Version = 0;
    this->ChangeList = 0;
    this->SessionTime = 0;
    this->ExclusiveSessionTime = 0;
    this->bExclusiveMissionActive = false;
    this->ExclusiveVersion = 0;
    this->ExclusiveChangeList = 0;
    this->bCompletedIntro = false;
    this->bSkippedLanguageCheck = false;
}

