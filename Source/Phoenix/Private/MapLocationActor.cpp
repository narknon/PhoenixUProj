#include "MapLocationActor.h"


void AMapLocationActor::OnPushBackward() {
}


void AMapLocationActor::OnBringForward() {
}


void AMapLocationActor::OnActivateHighlight(bool Activate) {
}

AMapLocationActor::AMapLocationActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CameraParameters = NULL;
    this->Visited = false;
    this->IsTower = false;
    this->HasMaterialInstance = false;
    this->TargetFocusPoint = NULL;
    this->bIsHighlighted = false;
    this->bIsForward = true;
}

