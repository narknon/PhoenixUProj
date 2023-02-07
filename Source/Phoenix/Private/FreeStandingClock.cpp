#include "FreeStandingClock.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"


void AFreeStandingClock::DoClockTick() {
}

AFreeStandingClock::AFreeStandingClock() {
    this->HandsComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Hands"));
    this->HourHand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hour_Hand"));
    this->MinuteHand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Minute_Hand"));
    this->HandRotateDuration = 0.50f;
    this->bHandsLookAtPlayer = false;
}

