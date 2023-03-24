#include "Train.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"

ATrain::ATrain(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TrainType = ETrainType::TRAIN_ENGINE;
    this->DockedFront = NULL;
    this->DesiredSpeed = 20.00f;
    this->DistanceAlongTrack = 0.00f;
    this->Train = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Train"));
    this->BogieFront = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BogieFront"));
    this->BogieBack = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BogieBack"));
    this->FrontAttatchment = CreateDefaultSubobject<USceneComponent>(TEXT("FrontAttatchment"));
    this->BackAttatchment = CreateDefaultSubobject<USceneComponent>(TEXT("BackAttatchment"));
    this->TrackSpline = NULL;
    this->AccelerationExp = 0.08f;
    this->RailZOffset = 0.00f;
    this->CurrentSpeed = 0.00f;
    this->SpeedToAnimationRatio = 10.00f;
}

