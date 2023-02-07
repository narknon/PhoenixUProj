#include "MultiFX2_FootprintInfo.h"

FMultiFX2_FootprintInfo::FMultiFX2_FootprintInfo() {
    this->Material = NULL;
    this->DirectionalDecal = false;
    this->FlipLeftFoot = false;
    this->DecalFrameCount = 0;
    this->FadeInDelay = 0.00f;
    this->FadeInTime = 0.00f;
    this->LifeSpan = 0.00f;
    this->FadeTime = 0.00f;
    this->bRenderAfterWeather = false;
}

