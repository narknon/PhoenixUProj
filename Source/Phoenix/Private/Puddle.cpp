#include "Puddle.h"

class AActor;

void APuddle::OnEndOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void APuddle::OnBeginOverlap(AActor* SelfActor, AActor* OtherActor) {
}

APuddle::APuddle(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PhysMat = NULL;
    this->Mesh = NULL;
}

