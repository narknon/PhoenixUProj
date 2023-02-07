#include "MaterialPermuterLibrary.h"

UMaterialPermuterLibrary::UMaterialPermuterLibrary() {
    this->InstanceHandCraftedLibrary = NULL;
    this->bEnableMIDCache = true;
    this->MIDCacheTimeoutSeconds = 8.00f;
}

