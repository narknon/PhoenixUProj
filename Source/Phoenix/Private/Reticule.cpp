#include "Reticule.h"


void UReticule::ShowTargetReticule(bool IsVisible) {
}

void UReticule::ShowCombatReticule(bool IsVisible) {
}

void UReticule::Show(bool IsVisible) {
}



void UReticule::SetState(EReticuleState State) {
}

void UReticule::SetFinisherNormalizedAngle(float NormalizedAngle) {
}

void UReticule::SetFinisherActive(bool FinisherActiveIn) {
}















EReticuleState UReticule::GetState() {
    return EReticuleState::RS_Unlocked;
}

bool UReticule::GetFinisherActive() {
    return false;
}

UReticule::UReticule() {
    this->IsSubReticuleVisible = false;
    this->UseWeakSub = false;
    this->SubReticuleMoveToTargetTime = 1.00f;
    this->FinisherMaxSpeed = 180.00f;
    this->FinisherAcceleration = 180.00f;
    this->IsFinisherOverlapped = false;
    this->IsBestFinisherOverlapped = false;
    this->PreventFinisherWhenNotOverlapped = false;
    this->UseLinearFinisherReticule = true;
    this->FinisherStartAngle = -90.00f;
    this->FinisherLinearStartDistance = 200.00f;
    this->InitialFinisherReticuleDelay = 1.00f;
    this->OverlapHalfAngle = 14.00f;
    this->BestOverlapHalfAngle = 7.00f;
    this->HoldFinisherTime = 2.00f;
    this->FinisherCircle = NULL;
    this->FinisherRing = NULL;
    this->FinisherCircleImage = NULL;
    this->FinisherRingImage = NULL;
    this->ReticulePanel = NULL;
    this->Primary = NULL;
    this->ReticuleState = EReticuleState::RS_Unlocked;
    this->IsReticuleVisible = false;
    this->IsCombatReticuleVisible = false;
    this->IsTargetReticuleVisible = true;
}

