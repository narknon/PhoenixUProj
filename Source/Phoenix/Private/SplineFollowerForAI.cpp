#include "SplineFollowerForAI.h"
#include "PathComponent.h"

class AActor;
class UScheduledEntity;

void ASplineFollowerForAI::UpdateSplineType(EPerformTaskSplineTypes NewSplineType) {
}

void ASplineFollowerForAI::StartAIMovementOnSpline(UScheduledEntity* InScheduledEntity, int32 ActivityTypeBits) {
}

void ASplineFollowerForAI::SetLumos(bool InbLumosOn) {
}

void ASplineFollowerForAI::OnWaitForPlayerComplete() {
}

void ASplineFollowerForAI::OnFleshLoadComplete(AActor* FleshActor) {
}

void ASplineFollowerForAI::MoveOnSplineFleshLoad(AActor* FleshActor) {
}

void ASplineFollowerForAI::CreateSplineFromGivenPoints() {
}

ASplineFollowerForAI::ASplineFollowerForAI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PathComponent = CreateDefaultSubobject<UPathComponent>(TEXT("Spline"));
    this->bDebugSpline = false;
    this->SplineType = EPerformTaskSplineTypes::Jog;
    this->bCanPlayerUseSpeedModifier = true;
    this->bStartAtSplineStart = true;
    this->bOrientTowardsPlayer = true;
    this->bInfluenceCamera = true;
    this->bLumosOn = false;
    this->bUseDetailPanelRadiusValues = false;
    this->CasualMode = false;
    this->JumpDisabled = false;
    this->DodgeDisabled = false;
    this->AimModeDisabled = false;
    this->SpellsDisabled = false;
    this->CommonInterruptParallelSceneRigActor = NULL;
    this->CommonResumeParallelSceneRigActor = NULL;
    this->CommonBarkParallelSceneRigActor = NULL;
    this->bClearParallelSceneRig = true;
    this->MissionUID = 0;
    this->StartMatchingPlayerSpeedRadius = 125.00f;
    this->BungeeRadius = 300.00f;
    this->TickDelays = 0.40f;
    this->EntryPointDistance = 30.00f;
    this->HeadTrackingCounter = 20;
    this->bPlayerDistanceFromSpline = false;
    this->bCanWait = true;
    this->StartWaitingProximityRadius = 400.00f;
    this->StopWaitingProximityRadius = 150.00f;
    this->PlayerDistanceFromSplineForWait = 600.00f;
    this->StartSlowWalkingProximityRadius = 300.00f;
    this->StartWalkingProximityRadius = 200.00f;
    this->StartJoggingProximityRadius = 100.00f;
    this->bRevertToOriginalSpeedMode = false;
    this->RevertToOrginalProximityRadius = 800.00f;
    this->bCanInterruptVO = false;
    this->InterruptVOProximityRadius = 800.00f;
    this->ResumeVOProximityRadius = 800.00f;
    this->BarkVOProximityRadius = 900.00f;
    this->OtherSplinePath = NULL;
    this->CameraInfluenceHandle = NULL;
}

