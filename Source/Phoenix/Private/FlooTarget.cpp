#include "FlooTarget.h"

void AFlooTarget::SetAvailable(bool availableIn) {
}


bool AFlooTarget::GetAvailable() {
    return false;
}

AFlooTarget::AFlooTarget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AvailableEmitter = NULL;
}

