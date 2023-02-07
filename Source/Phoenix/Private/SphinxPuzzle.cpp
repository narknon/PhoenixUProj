#include "SphinxPuzzle.h"
#include "InteractiveObjectComponent.h"

class AActor;


void ASphinxPuzzle::CleanUpObject(AActor* actorToDestroy) {
}

ASphinxPuzzle::ASphinxPuzzle() {
    this->InteractiveObjectComponent = CreateDefaultSubobject<UInteractiveObjectComponent>(TEXT("InteractiveObjectComponent"));
    this->PuzzleTypeName = TEXT("Undefined");
}

