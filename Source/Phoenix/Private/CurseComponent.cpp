#include "CurseComponent.h"

class AActor;
class UPrimitiveComponent;

void UCurseComponent::UncurseEnds() {
}

bool UCurseComponent::Uncurse(int32 UncurseLevel) {
    return false;
}

void UCurseComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void UCurseComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

bool UCurseComponent::IsCursed() {
    return false;
}

void UCurseComponent::ActivateCurseWithBuildup(AActor* Target) {
}

UCurseComponent::UCurseComponent() {
    this->VolumeComponent = NULL;
    this->BacklashOriginComponent = NULL;
    this->VFXPositionComponent = NULL;
    this->CurseLevel = 1;
    this->bUncursingIsPermanent = true;
    this->SpellToBeUsedOnInteract = NULL;
    this->CursedVfx = NULL;
    this->CursedSfx = NULL;
    this->BuildupTimeBeforeFiring = 1.00f;
    this->CursedBuildupVfx = NULL;
    this->CursedBuildupSfx = NULL;
    this->bUseVolumeOverlapEvent = false;
    this->CooldownBetweenSpells = 1.00f;
    this->NumberOfSpellsInSequence = 1;
    this->CooldownBetweenSequences = 5.00f;
    this->bKeepCurseZoneActiveWhenBroken = false;
    this->ParticleSystemComponent = NULL;
    this->BuildupParticleSystemComponent = NULL;
}

