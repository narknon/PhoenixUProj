#include "Puddle.h"

class AActor;

void APuddle::OnEndOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void APuddle::OnBeginOverlap(AActor* SelfActor, AActor* OtherActor) {
}

APuddle::APuddle() {
    this->PhysMat = NULL;
    this->Mesh = NULL;
}

