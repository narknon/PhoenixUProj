#include "WaterIgnoreVolume.h"
#include "Components/BoxComponent.h"

class AActor;
class UPrimitiveComponent;

void AWaterIgnoreVolume::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AWaterIgnoreVolume::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

AWaterIgnoreVolume::AWaterIgnoreVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->IgnoreOverlap = CreateDefaultSubobject<UBoxComponent>(TEXT("IgnoreBox"));
}

