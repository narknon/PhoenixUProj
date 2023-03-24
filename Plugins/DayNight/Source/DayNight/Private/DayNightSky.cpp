#include "DayNightSky.h"
#include "DayNightMasterComponent.h"
#include "NiagaraStarrySkySwitchableHighlightComponent.h"

class ADayNightSky;
class UObject;

void ADayNightSky::GetDayNightSky(UObject* WorldContextObject, ADayNightSky*& DayNightSkyActor) {
}

void ADayNightSky::EditLightRig() const {
}

void ADayNightSky::EditBasis() const {
}

ADayNightSky::ADayNightSky(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DayNightMaster = CreateDefaultSubobject<UDayNightMasterComponent>(TEXT("DayNightMaster"));
    this->TrackEyeXYRoot = NULL;
    this->GlobalLightingBlendable = NULL;
    this->GlobalLightingBlendablePriority = 998.00f;
    this->StarField = CreateDefaultSubobject<UNiagaraStarrySkySwitchableHighlightComponent>(TEXT("NiagaraStarField"));
    this->NightSkyVisibilityBlendDomainThreshold = 0.50f;
    this->bEnableSunDisk = true;
    this->bUseActorZForWorldOrigin = false;
    this->bUseHideStarsNormalizedTime = true;
    this->Compass = NULL;
}

