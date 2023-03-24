#include "StreamingPlaceholderSanctuaryIdentity.h"

void AStreamingPlaceholderSanctuaryIdentity::OnIdentityChanged(ESanctuaryIdentity OldIdentity, ESanctuaryIdentity NewIdentity) {
}

AStreamingPlaceholderSanctuaryIdentity::AStreamingPlaceholderSanctuaryIdentity(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutoSwapWhenIdentityChanges = true;
}

