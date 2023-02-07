#include "NPC_AbilityChannel.h"

FNPC_AbilityChannel::FNPC_AbilityChannel() {
    this->Channel = ENPC_AbilityChannel::FullBody;
    this->bEnable = false;
    this->OnState = 0;
    this->OnAnims = 0;
    this->OnContext = 0;
    this->ChannelAbilityPtr = NULL;
}

