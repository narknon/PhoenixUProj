#include "MercunaNavTestingActor.h"
#include "Components/SphereComponent.h"

void AMercunaNavTestingActor::OnSplineUpdate(EMercunaSplineEvent::Type SplineEvent) {
}

void AMercunaNavTestingActor::OnOctreeBuildComplete() {
}

AMercunaNavTestingActor::AMercunaNavTestingActor() {
    this->Radius = 50.00f;
    this->bSearchStart = false;
    this->OtherActor = NULL;
    this->HeightChangePenalty = 0.00f;
    this->bContinuouslyRepath = false;
    this->bDrawSpline = false;
    this->bDrawToScale = false;
    this->MaxSpeed = 300.00f;
    this->MaxAcceleration = 100.00f;
    this->bPathExist = false;
    this->bPathIsPartial = false;
    this->bPathIsOutOfNodes = false;
    this->PathLength = 0.00f;
    this->PathSections = 0;
    this->PathFindTime = 0.00f;
    this->PathNodesUsed = 0;
    this->SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    this->Spline = NULL;
    this->Octree = NULL;
}

