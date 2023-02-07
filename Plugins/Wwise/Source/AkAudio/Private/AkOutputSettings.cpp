#include "AkOutputSettings.h"

FAkOutputSettings::FAkOutputSettings() {
    this->IdDevice = 0;
    this->PanRule = PanningRule::PanningRule_Speakers;
    this->ChannelConfig = AkChannelConfiguration::Ak_Parent;
}

