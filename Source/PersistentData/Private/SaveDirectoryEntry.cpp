#include "SaveDirectoryEntry.h"

FSaveDirectoryEntry::FSaveDirectoryEntry() {
    this->AccountUserIndex = 0;
    this->CharacterID = 0;
    this->SaveType = ESaveType::NONE;
    this->bIsUsed = false;
    this->MajorVersion = 0;
    this->MinorVersion = 0;
}

