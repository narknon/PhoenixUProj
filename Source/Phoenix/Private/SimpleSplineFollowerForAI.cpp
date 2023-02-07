#include "SimpleSplineFollowerForAI.h"
#include "PathComponent.h"

class AActor;
class UScheduledEntity;

void ASimpleSplineFollowerForAI::StartAIMovementOnSpline(UScheduledEntity* InScheduledEntity, int32 ActivityTypeBits) {
}

void ASimpleSplineFollowerForAI::OnFleshLoadComplete(AActor* FleshActor) {
}

void ASimpleSplineFollowerForAI::MoveOnSplineFleshLoad(AActor* FleshActor) {
}

void ASimpleSplineFollowerForAI::CreateSplineFromGivenPoints() {
}

ASimpleSplineFollowerForAI::ASimpleSplineFollowerForAI() {
    this->PathComponent = CreateDefaultSubobject<UPathComponent>(TEXT("Spline"));
    this->bDebugSpline = false;
    this->SplineType = EPerformTaskSplineTypes::Jog;
    this->bSprintSplineType = false;
    this->bStartAtSplineStart = true;
    this->MissionUID = 0;
    this->OtherSplinePath = NULL;
}

