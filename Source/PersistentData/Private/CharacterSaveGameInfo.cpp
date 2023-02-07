#include "CharacterSaveGameInfo.h"

FCharacterSaveGameInfo::FCharacterSaveGameInfo() {
    this->CharacterID = 0;
    this->CharacterLevel = 0;
    this->CharacterGameDifficulty = 0;
    this->bIsUsed = false;
    this->VoicePitch = 0;
    this->CurrentFormat = ECharacterNameFormat::NONE;
}

