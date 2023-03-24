#include "ProxFloorBend.h"

class AActor;
class UAkComponent;
class UBoxComponent;
class UPrimitiveComponent;
class USceneComponent;
class UStaticMeshComponent;

void AProxFloorBend::UpdateRTPCValues() {
}

void AProxFloorBend::UpdateProxFloorBend(float Blend) {
}

void AProxFloorBend::UpdateCollisionResponse(float Blend) {
}

void AProxFloorBend::SetFloorLocation(UPrimitiveComponent* Obj, float Blend, FVector BaseLOC, FVector CompareLocation) {
}

void AProxFloorBend::ResetFloor() {
}

bool AProxFloorBend::ProxFloorBendSetUp(USceneComponent* i_SceneComponent, UStaticMeshComponent* i_NewFloor, UAkComponent* i_AkComponent, UBoxComponent* i_TriggerBox, AActor* i_ComparisonActor) {
    return false;
}

void AProxFloorBend::OnTimelineFinished() {
}

void AProxFloorBend::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AProxFloorBend::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

AProxFloorBend::AProxFloorBend(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Radius = 1000.00f;
    this->InnerRadius = 0.00f;
    this->Offset = 100.00f;
    this->BlendTime = 2.00f;
    this->FloorOffset = 5.00f;
    this->ZOffset = 1.00f;
    this->ZFloorBase = 0.00f;
    this->TraceDistance = 150.00f;
    this->bUseProxOffset = true;
    this->bSetUpOnPlay = false;
    this->bShowCollisionPlane = false;
    this->bHardFloorReset = false;
    this->OffsetDis = 0.00f;
    this->OffsetMultiplier = 0.00f;
    this->BaseHeight = 0.00f;
    this->NewFloorModifierX = 0.10f;
    this->NewFloorModifierY = 0.10f;
    this->StartAkEvent = NULL;
    this->StopAkEvent = NULL;
    this->FloorMoveLoopStartAkEvent = NULL;
    this->FloorMoveLoopStopAkEvent = NULL;
    this->FloorCurve = NULL;
    this->TimelineDirection = ETimelineDirection::Forward;
    this->SceneComponent = NULL;
    this->NewFloorComponent = NULL;
    this->AkProxFloorBend = NULL;
    this->TriggerBox = NULL;
    this->PlayerCharacter = NULL;
    this->ComparisonActor = NULL;
}

