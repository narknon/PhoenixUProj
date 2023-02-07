#include "ChannelingSpellTool.h"




bool AChannelingSpellTool::HasMinChannelingTimeBeenMet() {
    return false;
}

AChannelingSpellTool::AChannelingSpellTool() {
    this->ChargeVersionAvailable = true;
    this->DUMMY = false;
    this->bSetTargetTrackers = true;
    this->Dummy2 = false;
    this->ChargedMunitionDataAsset = NULL;
    this->BeamTargetActor = NULL;
}

