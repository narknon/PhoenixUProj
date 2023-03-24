#include "MountSpeedLimitVolume.h"

class AActor;
class UPrimitiveComponent;

void AMountSpeedLimitVolume::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AMountSpeedLimitVolume::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

AMountSpeedLimitVolume::AMountSpeedLimitVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bEnforceGroundGait = false;
    this->GroundGaitLimit = EMountGroundSpeedLimit::Walk;
    this->EnforcedGroundGait = ECreatureMovementSpeed::Num;
    this->bEnforceFlyingGait = false;
    this->FlyingGaitLimit = EMountFlyingSpeedLimit::Slow;
    this->EnforcedFlyingGait = EMountFlyingGait::Num;
}

