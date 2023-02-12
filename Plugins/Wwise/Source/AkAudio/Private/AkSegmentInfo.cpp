#include "AkSegmentInfo.h"

FAkSegmentInfo::FAkSegmentInfo() {
    this->CurrentPosition = 0;
    this->PreEntryDuration = 0;
    this->ActiveDuration = 0;
    this->PostExitDuration = 0;
    this->RemainingLookAheadTime = 0;
    this->BeatDuration = 0.00f;
    this->BarDuration = 0.00f;
    this->GridDuration = 0.00f;
    this->GridOffset = 0.00f;
}

