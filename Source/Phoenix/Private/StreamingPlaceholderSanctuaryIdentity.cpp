#include "StreamingPlaceholderSanctuaryIdentity.h"

void AStreamingPlaceholderSanctuaryIdentity::OnIdentityChanged(ESanctuaryIdentity OldIdentity, ESanctuaryIdentity NewIdentity) {
}

AStreamingPlaceholderSanctuaryIdentity::AStreamingPlaceholderSanctuaryIdentity() {
    this->bAutoSwapWhenIdentityChanges = true;
}

