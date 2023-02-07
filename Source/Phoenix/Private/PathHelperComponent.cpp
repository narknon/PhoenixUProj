#include "PathHelperComponent.h"

void UPathHelperComponent::StartStart() {
}

void UPathHelperComponent::StartRun() {
}


void UPathHelperComponent::StartHelp(TArray<FVector> InPath) {
}

void UPathHelperComponent::StartDeployTurn() {
}

void UPathHelperComponent::StartDeploy() {
}

void UPathHelperComponent::SetState(EHelperState InState) {
}

void UPathHelperComponent::SetNewStopAndAttractPoint(int32 Index, FVector Point, bool CreatePoint) {
}

void UPathHelperComponent::RunStart() {
}

void UPathHelperComponent::PopOutStart() {
}

void UPathHelperComponent::EndStart() {
}

void UPathHelperComponent::DeployTurnStart() {
}

void UPathHelperComponent::DeployStart() {
}

float UPathHelperComponent::CalculateAngleBetweenTwoVectors(FVector v1, FVector v2) {
    return 0.0f;
}

void UPathHelperComponent::AttractStart() {
}

UPathHelperComponent::UPathHelperComponent() {
    this->TravelSpeed = 700.00f;
    this->MinTravelSpeed = 50.00f;
    this->TravelTime = 12.00f;
    this->DistanceBeforeAttract = 1500.00f;
    this->Height = 100.00f;
    this->HelperRadius = 20.00f;
    this->Deflection = 50.00f;
    this->DelayBetweenPoints = 1.00f;
    this->StartDelay = 3.00f;
    this->AttractHoldTime = 3.00f;
    this->StartMoveDistSq = 120000.00f;
    this->bNearActivate = false;
    this->CameraRotationTime = 0.50f;
    this->DebugNumberOfPathPointsToShow = 100;
    this->bIsRunningHelp = false;
    this->bAllowCollisionDuringZip = false;
    this->bShowExitPath = true;
    this->bShowDebug = false;
    this->bJustFollowPath = false;
    this->bOrientActorToPath = true;
    this->bHideActorAtEnd = true;
    this->DistanceToAvatarSq = 0.00f;
    this->PlayerSpeed = 0.00f;
    this->PlayerToPathHelperDot = 0.00f;
    this->CurrentSpeed = 0.00f;
    this->FirstPointInViewIndex = 0;
    this->FirstPointInViewAchieved = false;
    this->MaxZipPointDistance = 1500.00f;
    this->SpawnDistance = 300.00f;
    this->MinSpawnDistance = 0.00f;
    this->ReverseSpawnDistance = 1400.00f;
    this->MinReverseSpawnDistance = 400.00f;
    this->EndPointIndex = -1;
    this->HasLineOfSight = true;
    this->UseCreatureAnimation = false;
    this->NumberOfFramesForTurn = 10;
}

