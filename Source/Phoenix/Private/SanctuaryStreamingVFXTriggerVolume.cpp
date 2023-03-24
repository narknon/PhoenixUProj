#include "SanctuaryStreamingVFXTriggerVolume.h"
#include "Components/BoxComponent.h"

class AActor;
class UNiagaraComponent;
class UParticleSystemComponent;
class UPrimitiveComponent;

void ASanctuaryStreamingVFXTriggerVolume::OnParticleSystemFinished(UParticleSystemComponent* PSystem) {
}

void ASanctuaryStreamingVFXTriggerVolume::OnOverlapStart(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ASanctuaryStreamingVFXTriggerVolume::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ASanctuaryStreamingVFXTriggerVolume::OnNiagaraFinished(UNiagaraComponent* PSystem) {
}

void ASanctuaryStreamingVFXTriggerVolume::OnIdentityChanged(ESanctuaryIdentity OldIdentity, ESanctuaryIdentity NewIdentity) {
}

ASanctuaryStreamingVFXTriggerVolume::ASanctuaryStreamingVFXTriggerVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutoSwapWhenIdentityChanges = false;
    this->BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
    this->PlayerTriggers = true;
    this->CameraTriggers = true;
    this->OffsetAmount = 1.00f;
    this->PlayerRelativeMovement = false;
    this->IsActivated = true;
}

