#include "MaterialPreLoadKeysActor.h"

void AMaterialPreLoadKeysActor::BuildPreLoads() {
}

AMaterialPreLoadKeysActor::AMaterialPreLoadKeysActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Priority = EMaterialPermuterLoadingPriority::Normal;
    this->bStaticLoad = true;
    this->LoadingBundle = NULL;
}

