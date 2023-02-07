#include "InventoryResult.h"

FInventoryResult::FInventoryResult() {
    this->Count = 0;
    this->Stolen = false;
    this->EconomyValue = 0;
    this->SellPrice = 0;
    this->SlotNumber = 0;
    this->MaxInventoryStack = 0;
    this->Droppable = false;
    this->UniqueItem = false;
    this->KeepOnReset = false;
    this->Reason = EInventoryChangeReason::INVENTORY_CHANGE_REASON_GENERIC;
    this->Delta = 0;
    this->OtherActor = NULL;
    this->Consumable = false;
    this->UsableFromInventory = false;
    this->Sellable = false;
    this->UpdateTime = 0;
}

