#include "EdurusRock.h"

void AEdurusRock::SetRockLaunchDelay(float Time) {
}

void AEdurusRock::SetRockIdleLocation(FVector TargetLoc) {
}

void AEdurusRock::LaunchRock() {
}

AEdurusRock::AEdurusRock(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->m_RockLaunchDelay = 5.00f;
    this->m_RockLaunchSpeed = 1000.00f;
    this->m_RockLaunchAcceleration = 1000.00f;
    this->m_RockIdleSpeed = 100.00f;
    this->m_RockIdleRotationSpeed = 10.00f;
}

