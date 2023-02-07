#include "SaveGameInfo.h"

FSaveGameInfo::FSaveGameInfo() {
    this->AccountUserIndex = 0;
    this->CharacterID = 0;
    this->SaveType = ESaveType::NONE;
    this->bIsUsed = false;
}

