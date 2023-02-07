#include "LockableComponent.h"

class AActor;
class AAmbulatory_Character;
class ALockable;
class UMeshComponent;
class UObject;
class UPrimitiveComponent;

void ULockableComponent::UpdateLockAfterChange(bool OpenLockable, bool ThrowLock, bool PlaySoundsAndEffects, bool DoChild) {
}

void ULockableComponent::UnlockTimeReached(const UObject* Caller) {
}

void ULockableComponent::UnlockIfLinked(UObject* Caller, const FName& inGroupName) {
}

void ULockableComponent::UnlockButtonReleasedEarly(const UObject* Caller) {
}

void ULockableComponent::UnlockButtonPressed(const UObject* Caller) {
}

void ULockableComponent::Unlock(bool OpenLockable, bool ThrowLock, bool PlaySoundsAndEffects, bool DoChild, bool FromMinigame) {
}

void ULockableComponent::PlayerHitByMunitions() {
}

void ULockableComponent::OnPlayerRemovedLock(AAmbulatory_Character* AmbulatoryCharacter) {
}

void ULockableComponent::OnLockSphereHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

bool ULockableComponent::HasKey() const {
    return false;
}

UMeshComponent* ULockableComponent::GetLockMeshComponent() const {
    return NULL;
}

ALockable* ULockableComponent::GetLockable() {
    return NULL;
}

void ULockableComponent::DestroyLock() {
}

bool ULockableComponent::CanPlayerUseAlohomoraOnLock() const {
    return false;
}

bool ULockableComponent::CanPlayerOpenLock() const {
    return false;
}

ULockableComponent::ULockableComponent() {
    this->LockMeshComponent = NULL;
    this->CalloutLocator = NULL;
    this->CognitionStimuliSource = NULL;
    this->LockHitSphere = NULL;
    this->SerializedVersion = 0;
    this->AlwaysFaceCamera = false;
    this->Socket = TEXT("Lock");
    this->Locked = false;
    this->AutomaticallyChangeLockStateWithKeyPossession = false;
    this->ShowLock = true;
    this->PerceptibleWhenLocked = true;
    this->LockPickParticleSystem = NULL;
    this->LockLocationUnlockParticleSystem = NULL;
    this->AlohomoraCompleteAbilityClass = NULL;
    this->AlohomoraFailTime = 0.50f;
    this->AlohomoraAtLevelTime = 7.00f;
    this->AlohomoraOneAboveTime = 3.00f;
    this->AlohomoraTwoAboveTime = 1.00f;
    this->UnlockWithKeyTime = 0.20f;
    this->TimeForWiggleSound = 0.50f;
    this->UnlockSound = NULL;
    this->UnlockingSound = NULL;
    this->UnlockingStopSound = NULL;
    this->VoidSound = NULL;
    this->WiggleSound = NULL;
    this->AddedSound = NULL;
    this->RemovedSound = NULL;
    this->HitByMunitionSound = NULL;
    this->ClosedWithLockSound = NULL;
    this->BumpedIntoLockSound = NULL;
    this->UnlockFailSound = NULL;
    this->HasBeenSetUp = false;
    this->DeleteThisComponent = false;
}

