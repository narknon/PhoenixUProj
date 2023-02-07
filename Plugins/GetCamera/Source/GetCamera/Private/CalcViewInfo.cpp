#include "CalcViewInfo.h"

FCalcViewInfo::FCalcViewInfo() {
    this->UniqueId = 0;
    this->PlayerIndex = 0;
    this->ViewIndex = 0;
    this->FOV = 0.00f;
    this->DesiredFOV = 0.00f;
    this->LastEyeAdaptationExposure = 0.00f;
    this->LastAverageSceneLuminance = 0.00f;
    this->PreExposure = 0.00f;
    this->FrameNumber = 0;
    this->ViewType = EWorldCalcSceneViewType::Player;
}

