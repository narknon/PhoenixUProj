#include "AkMainOutputSettings.h"

FAkMainOutputSettings::FAkMainOutputSettings() {
    this->DeviceID = 0;
    this->PanningRule = EAkPanningRule::Speakers;
    this->ChannelConfigType = EAkChannelConfigType::Anonymous;
    this->ChannelMask = 0;
    this->NumberOfChannels = 0;
}

