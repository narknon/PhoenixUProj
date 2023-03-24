#include "NoMountZoneVolume.h"

class AActor;
class UPrimitiveComponent;

void ANoMountZoneVolume::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ANoMountZoneVolume::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

ANoMountZoneVolume::ANoMountZoneVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ShieldMesh = NULL;
    this->NoMountZoneError = ENoMountZoneError::Error_OutOfBounds;
    this->bGenerateShieldMesh = false;
    this->bAlternateStencilValues = false;
    this->Version = ENoMountZoneVersion::NoVersion;
    this->ConversionTempModel = NULL;
}

