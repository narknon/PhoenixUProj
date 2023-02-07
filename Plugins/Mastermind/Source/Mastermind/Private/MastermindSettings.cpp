#include "MastermindSettings.h"

UMastermindSettings::UMastermindSettings() {
    this->MastermindTickInterval = 0.50f;
    this->bIsActivatedByDefault = false;
    this->MastermindTCPPort = 13650;
    this->MaxClientConnections = 8;
}

