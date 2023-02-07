#include "UDSManager.h"

void UUDSManager::SyncUDSWithGameData() {
}

void UUDSManager::ResetPlayerStateIfCurrentSaveDeleted(int32 DeletedCharacterId) {
}

void UUDSManager::LoadPlayerStateFromSaveFile() {
}

void UUDSManager::InjectPlayerStateIntoSaveFile() {
}

UUDSManager::UUDSManager() {
    this->UDSStatManager = NULL;
    this->UDSIntentManager = NULL;
    this->UDSMechanicManager = NULL;
    this->UDSActivityManager = NULL;
    this->UDSFieldGuideManager = NULL;
    this->UDSLocationManager = NULL;
    this->UDSEventQueuer = NULL;
}

