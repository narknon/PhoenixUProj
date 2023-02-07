#include "SceneGroup_SanctuaryIdentity.h"

void USceneGroup_SanctuaryIdentity::OnIdentityChanged(ESanctuaryIdentity OldIdentity, ESanctuaryIdentity NewIdentity) {
}

USceneGroup_SanctuaryIdentity::USceneGroup_SanctuaryIdentity() {
    this->Identity = ESanctuaryIdentity::Default;
}

