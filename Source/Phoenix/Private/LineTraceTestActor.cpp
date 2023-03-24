#include "LineTraceTestActor.h"

ALineTraceTestActor::ALineTraceTestActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TraceLength = 100.00f;
    this->bTraceComplex = false;
    this->QueryMobilityType = ELineTraceTestActorQueryMobilityType::Any;
    this->LineTraceBy = ELineTraceTestActorTraceType::Channel;
    this->SelectedChannel = ELineTraceTestActorCollisionChannel::WorldStatic;
    this->SelectedObjectType = ELineTraceTestActorObjectTypeQuery::WorldStatic;
    this->SelectedProfileName = TEXT("BlockAll");
}

