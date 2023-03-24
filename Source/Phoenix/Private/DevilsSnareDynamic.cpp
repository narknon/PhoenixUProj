#include "DevilsSnareDynamic.h"
#include "Components/SphereComponent.h"

class AActor;
class UPrimitiveComponent;

bool ADevilsSnareDynamic::UnslowPlayer() {
    return false;
}



bool ADevilsSnareDynamic::SlowPlayer(float SpeedLimit) {
    return false;
}

void ADevilsSnareDynamic::PlayerLumosStart() {
}

void ADevilsSnareDynamic::PlayerLumosEnd() {
}

void ADevilsSnareDynamic::OnOverlapSphereEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ADevilsSnareDynamic::OnOverlapSphereBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

bool ADevilsSnareDynamic::FindClosestLightSourcePos(const FVector& SnarePos, FVector& OutPos) {
    return false;
}

void ADevilsSnareDynamic::BeginPlayDelayed() {
}

ADevilsSnareDynamic::ADevilsSnareDynamic(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    this->bPlayerIsUsingLumos = false;
    this->SphereRadius = 1000.00f;
    this->OnFireRadiusExtension = 600.00f;
}

