#include "TickSequencerSingleton.h"
#include "TickSequencerUpdateComponentDuringPhysics.h"
#include "TickSequencerUpdateComponentPostActorTickUpdate.h"
#include "TickSequencerUpdateComponentPostPhysics.h"
#include "TickSequencerUpdateComponentPostUpdateWork.h"
#include "TickSequencerUpdateComponentPreActorTickUpdate.h"
#include "TickSequencerUpdateComponentPrePhysics.h"

void ATickSequencerSingleton::ForceTick() {
}

ATickSequencerSingleton::ATickSequencerSingleton() {
    this->PrePhysicsBuckets = CreateDefaultSubobject<UTickSequencerUpdateComponentPrePhysics>(TEXT("PrePhysicsBuckets"));
    this->DuringPhysicsBuckets = CreateDefaultSubobject<UTickSequencerUpdateComponentDuringPhysics>(TEXT("DuringPhysicsBuckets"));
    this->PostPhysicsBuckets = CreateDefaultSubobject<UTickSequencerUpdateComponentPostPhysics>(TEXT("PostPhysicsBuckets"));
    this->PostUpdateWorkBuckets = CreateDefaultSubobject<UTickSequencerUpdateComponentPostUpdateWork>(TEXT("PostUpdateWork"));
    this->PreActorTickBuckets = CreateDefaultSubobject<UTickSequencerUpdateComponentPreActorTickUpdate>(TEXT("PreActorTick"));
    this->PostActorTickBuckets = CreateDefaultSubobject<UTickSequencerUpdateComponentPostActorTickUpdate>(TEXT("PostActorTick"));
    this->LastGetExtraBucketsFrame = 0;
    this->CachedDynamicBucketGroup = ETickSequencerGroup::DuringPhysics;
    this->bUseExternalPostActorTick = false;
    this->ManualTickFrame = 0;
}

