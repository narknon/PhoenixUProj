#include "OverlapEffectsHandlerWindSpeed.h"

UOverlapEffectsHandlerWindSpeed::UOverlapEffectsHandlerWindSpeed() {
    this->ActorWindSpeedRTPC = TEXT("ActorWindSpeed");
    this->ActorIndoorsRTPC = TEXT("ActorIndoors");
    this->ActorClothingTypeRTPC = TEXT("ActorClothingType");
    this->UpdateRateMS = 200;
    this->NextUpdate = 0.00f;
    this->ClothingTypes = -1;
    this->LastActorWindSpeedRTPC = -1.00f;
    this->LastActorIndoorsRTPC = -1.00f;
    this->LastActorClothingTypeRTPC = 255;
    this->bUseRelativeWindVelocity = false;
    this->bUseActorWindSpeedRTPC = true;
    this->bUseActorIndoorsRTPC = true;
    this->bUseActorClothingTypeRTPC = true;
}

