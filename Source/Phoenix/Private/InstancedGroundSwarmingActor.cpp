#include "InstancedGroundSwarmingActor.h"
#include "Components/InstancedStaticMeshComponent.h"

class AActor;

void AInstancedGroundSwarmingActor::Stop() {
}

void AInstancedGroundSwarmingActor::SetTargetFocii(AActor* Target) {
}

void AInstancedGroundSwarmingActor::Reset() {
}

void AInstancedGroundSwarmingActor::Regenerate() {
}

void AInstancedGroundSwarmingActor::Pause() {
}

void AInstancedGroundSwarmingActor::IsRunning(bool& bIsRunning) const {
}

bool AInstancedGroundSwarmingActor::IsExiting() const {
    return false;
}

void AInstancedGroundSwarmingActor::Go() {
}

void AInstancedGroundSwarmingActor::Generate() {
}

void AInstancedGroundSwarmingActor::BeginExiting(EGroundSwarmingExitType Type, bool disableTargets) {
}

AInstancedGroundSwarmingActor::AInstancedGroundSwarmingActor() {
    this->GroundSwarmMeshes = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("GroundSwarmMeshes"));
    this->FollowForceModifier = 1.00f;
    this->InitialSpawnHiddenPercent = 50.00f;
    this->InitialSpawnHiddenTimeMin = 1.00f;
    this->InitialSpawnHiddenTimeMax = 2.00f;
    this->InitialFreezeTimeMin = 0.00f;
    this->InitialFreezeTimeMax = 1.00f;
    this->InitialShapeTo = NULL;
    this->OnSwarmStartAudio = NULL;
    this->OnSwarmDispersedAudio = NULL;
    this->bSwarmStartDisperseMulti = false;
    this->OnHitTarget = NULL;
    this->OnHitTargetAudio = NULL;
    this->OnKillVolume = NULL;
    this->OnKillVolumeAudio = NULL;
    this->OnPoof = NULL;
    this->OnPoofAudio = NULL;
    this->OnBurrow = NULL;
    this->OnBurrowAudio = NULL;
    this->OnBurrowUpOffset = 5.00f;
    this->Timeout = 0.00f;
    this->TimeoutModifier = 1.00f;
    this->TargetThresholdPercent = 25.00f;
    this->TargetThresholdDelay = 3.00f;
    this->bAutoStart = true;
    this->bAutoDestroyWhenDone = false;
    this->SwarmAudioSource = NULL;
    this->bShapeApplied = false;
    this->bSignalledDestroyWhenDone = false;
    this->bSwarmAudioEnded = false;
}

