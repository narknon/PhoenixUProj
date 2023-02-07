#include "MotionWarpingUtilities.h"

class UAnimSequenceBase;

FAvaMotionWarpingSyncPoint UMotionWarpingUtilities::MakeMotionWarpingSyncPoint(FVector Location, FRotator Rotation) {
    return FAvaMotionWarpingSyncPoint{};
}

FTransform UMotionWarpingUtilities::ExtractRootMotionFromAnimation(const UAnimSequenceBase* Animation, float StartTime, float EndTime) {
    return FTransform{};
}

void UMotionWarpingUtilities::BreakMotionWarpingSyncPoint(const FAvaMotionWarpingSyncPoint& SyncPoint, FVector& Location, FRotator& Rotation) {
}

UMotionWarpingUtilities::UMotionWarpingUtilities() {
}

