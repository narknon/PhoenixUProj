#include "FlyingStairs.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

void AFlyingStairs::DestroyRandomStairChain() {
}

void AFlyingStairs::BuildRandomStairChain() {
}

AFlyingStairs::AFlyingStairs(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FlyingStairsArea = CreateDefaultSubobject<UCapsuleComponent>(TEXT("FlyingStairsArea"));
    this->CloudMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Cloud"));
    this->TimeForStairsToStayAtHeightDuringMovement = 3.00f;
    this->TimeForRandomlyBuildingStair = 30.00f;
}

