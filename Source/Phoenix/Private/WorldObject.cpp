#include "WorldObject.h"

bool AWorldObject::TryCreateBeacon() {
    return false;
}

void AWorldObject::OnAboutToSaveGame() {
}


AWorldObject::AWorldObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

