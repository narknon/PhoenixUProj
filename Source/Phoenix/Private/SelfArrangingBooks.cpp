#include "SelfArrangingBooks.h"

void ASelfArrangingBooks::UpdateBookTransform(const int32 idx, const float Path, const float Rot) {
}

void ASelfArrangingBooks::OnTimelineUpdate(float Value) {
}

void ASelfArrangingBooks::OnTimelineFinished() {
}

ASelfArrangingBooks::ASelfArrangingBooks(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RandomSelection = 0;
    this->bCanPlay = true;
    this->bPlayReverse = false;
    this->NumberOfBooks = 4;
    this->NumberOfPaths = 2;
    this->ScaleOfProps = 0.00f;
    this->spacing = 0.05f;
    this->DistanceInbetweenProps = 0.00f;
    this->TM_Spline = NULL;
    this->PathCurve = NULL;
    this->Rot1Curve = NULL;
    this->Rot2Curve = NULL;
    this->Rot3Curve = NULL;
    this->Rot4Curve = NULL;
}

