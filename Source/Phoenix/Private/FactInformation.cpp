#include "FactInformation.h"

FFactInformation::FFactInformation() {
    this->HasFactSheet = false;
    this->CurrentKnowledgeLevel = EKnowledgeLevel::Unknown;
    this->NeededKnowledgeLevel = EKnowledgeLevel::Unknown;
    this->SecretFactLocked = false;
}

