#include "TickSequencerBucketDelegateOptions.h"

FTickSequencerBucketDelegateOptions::FTickSequencerBucketDelegateOptions() {
    this->bTickWhenPaused = false;
    this->bSuspend = false;
    this->bTickInEditor = false;
    this->bTickOnlyInEditor = false;
}

