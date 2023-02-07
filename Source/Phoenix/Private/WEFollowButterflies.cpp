#include "WEFollowButterflies.h"
#include "Components/SphereComponent.h"
#include "Components/SplineComponent.h"

class AActor;
class UPrimitiveComponent;

void AWEFollowButterflies::StartMovement() {
}

void AWEFollowButterflies::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}



AWEFollowButterflies::AWEFollowButterflies() {
    this->ButterflySpline = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
    this->OverlapSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
    this->Billboard = NULL;
    this->ButterflyMoveSpeed = 3.00f;
    this->TreasureChestClass = NULL;
    this->TreasureChestYaw = 90.00f;
    this->FBDressingClass = NULL;
    this->HiddenChest = NULL;
    this->EventDressing = NULL;
    this->ButterfliesHideCount = 15;
    this->StartButterflies = NULL;
}

