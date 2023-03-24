#include "AncientMagicNova.h"

class UObject;

void AAncientMagicNova::SetNotifyObject(UObject* Object) {
}

AAncientMagicNova::AAncientMagicNova(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ExpandSpeed = 25.00f;
    this->MaxExpandSize = 1500.00f;
}

