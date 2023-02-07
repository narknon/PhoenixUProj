#include "ItemProperties.h"

FItemProperties::FItemProperties() {
    this->EconomyValue = 0;
    this->SellPrice = 0;
    this->Inventoryable = false;
    this->Persistent = false;
    this->Consumable = false;
    this->bTriggerAbilityOnConsume = false;
    this->Giftable = false;
    this->Sellable = false;
    this->Dropable = false;
    this->MaxInventoryStack = 0;
    this->UsableFromInventory = false;
    this->ItemLevel = 0;
}

