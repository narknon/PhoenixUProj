#include "AkSettingsPerUser.h"

UAkSettingsPerUser::UAkSettingsPerUser() {
    this->EnableAutomaticAssetSynchronization = false;
    this->WaapiIPAddress = TEXT("127.0.0.1");
    this->WaapiPort = 8080;
    this->bAutoConnectToWAAPI = false;
    this->AutoSyncSelection = true;
    this->SuppressWwiseProjectPathWarnings = true;
    this->SoundDataGenerationSkipLanguage = false;
}

