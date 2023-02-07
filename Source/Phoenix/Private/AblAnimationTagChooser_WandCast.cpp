#include "AblAnimationTagChooser_WandCast.h"

UAblAnimationTagChooser_WandCast::UAblAnimationTagChooser_WandCast() {
    this->SpinMoveBlendTime = 0.00f;
    this->MeleeMoveBlendTime = 0.10f;
    this->WandCastCommand = EWandCastCommand::HeavyDirectional;
    this->bSampleYawRemainingFromCurve = false;
    this->YawRemainingSampleEndTime = -1.00f;
}

