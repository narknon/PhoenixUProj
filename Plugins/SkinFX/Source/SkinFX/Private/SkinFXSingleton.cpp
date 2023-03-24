#include "SkinFXSingleton.h"

ASkinFXSingleton::ASkinFXSingleton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Library = NULL;
    this->DataDependencies = NULL;
    this->bSignalledAllReady = false;
}

