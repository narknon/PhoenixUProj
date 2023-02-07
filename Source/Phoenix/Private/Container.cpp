#include "Container.h"
#include "PadlockComponent.h"

AContainer::AContainer() {
    this->Open = false;
    this->PropIndex = -1;
    this->Lid_Rot_X = -14.00f;
    this->RandomZRotation = 0.00f;
    this->EnvInt = 0;
    this->SimulatePhysics = false;
    this->AutoSelectLoot = true;
    this->LockLevel = 0;
    this->Stat_MinValue = 0;
    this->ExpiryTime = 259200;
    this->SerializedContainerVersion = 0;
    this->PadlockComponent = CreateDefaultSubobject<UPadlockComponent>(TEXT("PadlockComponent"));
}

