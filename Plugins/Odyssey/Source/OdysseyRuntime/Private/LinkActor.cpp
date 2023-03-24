#include "LinkActor.h"

ALinkActor::ALinkActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LinkType = ELinkType::JUMP_LINK;
    this->NavLayers = 1;
    this->Bidirectional = true;
    this->Cost = 1.00f;
    this->MustUseDist = 40.00f;
    this->MaxSimultaneous = 0;
    this->DelayBeforeNextUser = 0.00f;
}

