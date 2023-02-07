#include "MillisecondUpdateTracker.h"

FMillisecondUpdateTracker::FMillisecondUpdateTracker() {
    this->LastMS = 0.00f;
    this->AverageMS = 0.00f;
    this->AverageSamples = 0;
    this->AverageMaxSamples = 0;
    this->bAverageRollover = false;
}

