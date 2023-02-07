#include "AbleSettings.h"

UAbleSettings::UAbleSettings() {
    this->m_EnableAsync = true;
    this->m_AllowAsyncAbilityUpdate = true;
    this->m_AllowAsyncCooldownUpdate = true;
    this->m_LogAbilityFailues = true;
    this->m_LogVerbose = true;
    this->m_EchoVerboseToScreen = false;
    this->m_VerboseScreenOutputLifetime = 2.00f;
}

