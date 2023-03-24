#include "SphinxPuzzle.h"
#include "InteractiveObjectComponent.h"

class AActor;


void ASphinxPuzzle::CleanUpObject(AActor* actorToDestroy) {
}

ASphinxPuzzle::ASphinxPuzzle(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InteractiveObjectComponent = CreateDefaultSubobject<UInteractiveObjectComponent>(TEXT("InteractiveObjectComponent"));
    this->PuzzleTypeName = TEXT("Undefined");
}

