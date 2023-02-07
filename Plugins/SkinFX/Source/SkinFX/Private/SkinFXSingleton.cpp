#include "SkinFXSingleton.h"

ASkinFXSingleton::ASkinFXSingleton() {
    this->Library = NULL;
    this->DataDependencies = NULL;
    this->bSignalledAllReady = false;
}

