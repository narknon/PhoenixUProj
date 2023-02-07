#include "LoadingScreenDescription.h"

FLoadingScreenDescription::FLoadingScreenDescription() {
    this->MinimumLoadingScreenDisplayTime = 0.00f;
    this->bAutoCompleteWhenLoadingCompletes = false;
    this->bMoviesAreSkippable = false;
    this->bWaitForManualStop = false;
    this->PlaybackType = MT_Normal;
    this->bShowUIOverlay = false;
    this->ImageStretch = EStretch::None;
}

