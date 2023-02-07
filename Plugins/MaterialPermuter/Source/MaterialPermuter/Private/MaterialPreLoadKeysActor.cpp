#include "MaterialPreLoadKeysActor.h"

void AMaterialPreLoadKeysActor::BuildPreLoads() {
}

AMaterialPreLoadKeysActor::AMaterialPreLoadKeysActor() {
    this->Priority = EMaterialPermuterLoadingPriority::Normal;
    this->bStaticLoad = true;
    this->LoadingBundle = NULL;
}

