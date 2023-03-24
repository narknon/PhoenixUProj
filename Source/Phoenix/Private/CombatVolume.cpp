#include "CombatVolume.h"
#include "Components/BoxComponent.h"
#include "CombatVolumeGroup.h"

class AActor;
class UPrimitiveComponent;

void ACombatVolume::OnActorSpawnInFinished(AActor* SpawnedActor) {
}

void ACombatVolume::OnActorDeadEvent(AActor* DeadActor) {
}

UCombatVolumeGroup* ACombatVolume::GetGroup() {
    return NULL;
}

void ACombatVolume::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ACombatVolume::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

ACombatVolume::ACombatVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OwningGroup = CreateDefaultSubobject<UCombatVolumeGroup>(TEXT("Default__CombatVolume_Group"));
    this->bStartEncounterOnEnter = true;
    this->PlayerClearDistance = 1800.00f;
    this->BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Combat_Volume_Box"));
    this->LinkedDOVCollection = NULL;
}

