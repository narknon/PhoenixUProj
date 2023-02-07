#include "SanctuaryLightingIdentityMaster.h"
#include "SanctuaryLightingIdentityMasterComponent.h"

ASanctuaryLightingIdentityMaster::ASanctuaryLightingIdentityMaster() {
    this->MasterComponent = CreateDefaultSubobject<USanctuaryLightingIdentityMasterComponent>(TEXT("MasterComponent"));
}

