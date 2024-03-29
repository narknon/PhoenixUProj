#include "RiverSectionAudio.h"
#include "AkComponent.h"

ARiverSectionAudio::ARiverSectionAudio(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bRelativeLocations = false;
    this->AkComponent = CreateDefaultSubobject<UAkComponent>(TEXT("AkAudioComponent"));
    this->ClosestIndex = 0;
    this->CurrSpeedOfFlow = 0.00f;
}

