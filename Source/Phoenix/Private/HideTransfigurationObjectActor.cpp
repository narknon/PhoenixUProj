#include "HideTransfigurationObjectActor.h"
#include "Components/BoxComponent.h"

class AActor;

void AHideTransfigurationObjectActor::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor) {
}

AHideTransfigurationObjectActor::AHideTransfigurationObjectActor() {
    this->BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
}

