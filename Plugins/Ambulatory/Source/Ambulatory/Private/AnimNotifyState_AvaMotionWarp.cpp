#include "AnimNotifyState_AvaMotionWarp.h"

class UAnimSequenceBase;
class UAvaMotionWarpWindowFinder;

void UAnimNotifyState_AvaMotionWarp::AddMotionWarpModifier_Implementation(FAvaRootMotionWarper& InMotionWarper, UAvaMotionWarpWindowFinder* InWindowFinder, UAnimSequenceBase* InAnimation, float StartTime, float EndTime) const {
}

UAnimNotifyState_AvaMotionWarp::UAnimNotifyState_AvaMotionWarp() {
    this->RootMotionModifierConfig = NULL;
}

