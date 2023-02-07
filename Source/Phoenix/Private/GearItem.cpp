#include "GearItem.h"

FGearItem::FGearItem() {
    this->SlotID = EGearSlotIDEnum::HEAD;
    this->GearLevel = 0;
    this->OffenseStat = 0;
    this->DefenseStat = 0;
    this->CooldownStat = 0;
    this->bHoodUp = false;
    this->IsIdentified = 0;
    this->StatUpgrades = 0;
}

