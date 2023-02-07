#include "SocapAmendInfo.h"

FSocapAmendInfo::FSocapAmendInfo() {
    this->MyActor = NULL;
    this->Delta = 0;
    this->Action = SOCIAL_ACTION_ACCIO;
    this->Reason = SOCAP_CHANGE_DEBUG;
    this->Semantic = SOCIAL_SEMANTIC_ALARM;
    this->StatusNameHint = 0;
}

