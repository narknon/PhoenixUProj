#include "Portkey_Object.h"

void APortkey_Object::EndTeleport() {
}

APortkey_Object::APortkey_Object(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ActorOwner = NULL;
    this->Portkey_Mesh = NULL;
    this->PortkeyBase = NULL;
}

