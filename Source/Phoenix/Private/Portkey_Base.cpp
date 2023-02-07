#include "Portkey_Base.h"

class AActor;
class UPrimitiveComponent;

void APortkey_Base::PortkeyTeleport() {
}

void APortkey_Base::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

APortkey_Base::APortkey_Base() {
    this->bReturnToBase = true;
    this->PortkeyObject = NULL;
    this->bStartingAtBase = false;
}

