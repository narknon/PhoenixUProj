#include "RandomEncounterActor.h"

bool ARandomEncounterActor::IsActive() {
    return false;
}

void ARandomEncounterActor::ForceDeactivate() {
}

void ARandomEncounterActor::ForceActivate() {
}

ARandomEncounterActor::ARandomEncounterActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

