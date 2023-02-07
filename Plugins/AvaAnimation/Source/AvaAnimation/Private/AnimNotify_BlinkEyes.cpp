#include "AnimNotify_BlinkEyes.h"
#include "PoseSampler_BlinkEyes.h"

UAnimNotify_BlinkEyes::UAnimNotify_BlinkEyes() {
    this->bDoubleBlink = false;
    this->BlinkSpeed = 1.00f;
    this->PoseSampler = CreateDefaultSubobject<UPoseSampler_BlinkEyes>(TEXT("PoseSampler"));
}

