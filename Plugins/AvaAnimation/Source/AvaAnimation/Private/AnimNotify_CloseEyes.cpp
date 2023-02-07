#include "AnimNotify_CloseEyes.h"
#include "PoseSampler_CloseEyes.h"

UAnimNotify_CloseEyes::UAnimNotify_CloseEyes() {
    this->PoseSampler = CreateDefaultSubobject<UPoseSampler_CloseEyes>(TEXT("PoseSampler"));
}

