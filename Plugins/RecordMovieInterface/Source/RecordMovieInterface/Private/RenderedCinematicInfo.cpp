#include "RenderedCinematicInfo.h"

FRenderedCinematicInfo::FRenderedCinematicInfo() {
    this->bUploadToShotgun = false;
    this->bWasRenderSuccessful = false;
    this->bAudioOnly = false;
    this->bHasOverlay = false;
    this->bUsingUnlit = false;
    this->DesiredRecordTime = 0;
    this->ActualRecordTime = 0;
}

