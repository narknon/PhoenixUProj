#include "CharacterBoneProjector.h"

class AActor;

void UCharacterBoneProjector::Update(AActor* Owner, float dt) {
}

bool UCharacterBoneProjector::StatesInitialized() const {
    return false;
}

bool UCharacterBoneProjector::InitializeState(AActor* Owner) {
    return false;
}

UCharacterBoneProjector::UCharacterBoneProjector() {
    this->bStatesInitialized = false;
}

