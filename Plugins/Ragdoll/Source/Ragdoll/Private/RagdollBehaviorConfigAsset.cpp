#include "RagdollBehaviorConfigAsset.h"

URagdollBehaviorConfigAsset::URagdollBehaviorConfigAsset() {
    this->BehaviorProfile = NULL;
    this->AudioBehaviorProfile = NULL;
    this->RecoveryAssistBehaviorProfile = NULL;
    this->RagdollShoulderLeftName = TEXT("ragdollShoulderLeftSocket");
    this->RagdollShoulderRightName = TEXT("ragdollShoulderRightSocket");
    this->RagdollHipsLeftName = TEXT("ragdollHipsLeftSocket");
    this->RagdollHipsRightName = TEXT("ragdollHipsRightSocket");
    this->RagdollSpineLowerBoneName = TEXT("ragdollSpineLowerSocket");
    this->RagdollSpineUpperBoneName = TEXT("ragdollSpineUpperSocket");
    this->NavigationLayer = 0;
    this->MinMoveDist2DRetestNavPosition = 100.00f;
    this->MaxGroundTestDistance = 1000.00f;
}

