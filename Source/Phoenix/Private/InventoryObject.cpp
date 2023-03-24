#include "InventoryObject.h"

void AInventoryObject::SetItemData(FName ItemId, int32 ItemCount, FName InVariation, bool InIsStolen, bool InIsUnique) {
}


void AInventoryObject::AddPickedUpHandler(const AInventoryObject::FOnPickedUpHandler& Handler) {
}

AInventoryObject::AInventoryObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UnitCount = 1;
    this->IsStolen = false;
    this->IsUnique = false;
    this->RespawnTime = 259200;
    this->SpawnType = InventoryObjectInLevel;
    this->m_pickupSfx = NULL;
}

