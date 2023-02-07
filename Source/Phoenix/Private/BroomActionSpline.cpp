#include "BroomActionSpline.h"
#include "Components/SplineComponent.h"

void ABroomActionSpline::TriggerEndBehaviour(bool bOverrideEndBehaviour, EActionsCompleteBehaviour EndBehaviourOverride) {
}

void ABroomActionSpline::StartBroomActionSequence() {
}

void ABroomActionSpline::OnSaveGameLoaded() {
}

void ABroomActionSpline::OnGameToBeSaved() {
}

ABroomActionSpline::ABroomActionSpline() {
    this->SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("TrackSpline"));
    this->bForceHighLOD = false;
    this->bMountIfNotAlready = true;
    this->BroomToUse = NULL;
    this->BroomPhysicsData = NULL;
    this->EndBehaviour = EActionsCompleteBehaviour::None;
    this->NextBroomActionSpline = NULL;
    this->bSaveState = false;
    this->bSaveTaskState = false;
    this->NPCBroom = NULL;
}

