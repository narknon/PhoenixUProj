#include "ArchitectGameInstance.h"

class UArchitectGameInstance;

UArchitectGameInstance* UArchitectGameInstance::GetArchitectGameInstance() {
    return NULL;
}

UArchitectGameInstance::UArchitectGameInstance() {
    this->MonolithicObjectArchitectAsset = NULL;
    this->PreloadMonolithicArchitectAsset = NULL;
}

