#include "FlyingStairsChain.h"
#include "Components/CapsuleComponent.h"

class AActor;
class UFlyingStairComponent;
class UPrimitiveComponent;

void AFlyingStairsChain::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AFlyingStairsChain::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void AFlyingStairsChain::OnFlyingStairComponentDemolish(UFlyingStairComponent* FlyingStairComponent, float animationLength, float animationStartPosition) {
}

void AFlyingStairsChain::OnFlyingStairComponentBuild(UFlyingStairComponent* FlyingStairComponent, float animationLength, float animationStartPosition) {
}

void AFlyingStairsChain::DemolishNext() {
}

void AFlyingStairsChain::BuildNext() {
}

AFlyingStairsChain::AFlyingStairsChain(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FlyingStairsChainArea = CreateDefaultSubobject<UCapsuleComponent>(TEXT("FlyingStairsChainArea"));
    this->TimeBetweenAutomaticSequentialBuilding = 1.00f;
    this->SpeedOfStairsFromCloud = 3;
    this->bBuildWholeChainWhenCharacterEntersRange = true;
}

