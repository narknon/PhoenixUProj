#include "EncounterLocationCreator.h"

void AEncounterLocationCreator::AttachObjectsToCreator(bool bInAttachObjects) {
}

void AEncounterLocationCreator::AttachEncompassingStations(const FString& ObjectName) {
}

AEncounterLocationCreator::AEncounterLocationCreator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StationCreatorName = TEXT("LocationCreator");
    this->LocationEncounter = NULL;
}

