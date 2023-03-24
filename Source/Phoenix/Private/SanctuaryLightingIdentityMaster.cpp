#include "SanctuaryLightingIdentityMaster.h"
#include "SanctuaryLightingIdentityMasterComponent.h"

ASanctuaryLightingIdentityMaster::ASanctuaryLightingIdentityMaster(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MasterComponent = CreateDefaultSubobject<USanctuaryLightingIdentityMasterComponent>(TEXT("MasterComponent"));
}

