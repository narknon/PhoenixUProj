#include "RiverVolume.h"
#include "Components/StaticMeshComponent.h"

class AActor;
class UPrimitiveComponent;
class UStaticMesh;

void ARiverVolume::SetupRiver(FTransform i_RiverTransform, FVector i_RiverAveDir, TMap<FVector, FVector2D> i_RiverFlowPoints, FBoxSphereBounds i_WaterBoxInfo, float i_VolumeZRotation, UStaticMesh* i_RiverMesh, UStaticMesh* i_DeepCollision, UStaticMesh* i_ShallowCollision, bool i_bFlowInLake, bool i_bFlowOutLake) {
}

void ARiverVolume::OnLakeSphereOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ARiverVolume::OnActorOverlapEnd(AActor* OverlappedActor, AActor* OtherActor) {
}

FVector2D ARiverVolume::GetForceVector(UPrimitiveComponent* PrimComp, bool bUseDist) {
    return FVector2D{};
}

ARiverVolume::ARiverVolume() {
    this->RiverMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RiverMesh"));
    this->RiverFlowSpeed = 2000.00f;
    this->bDebugFlowView = false;
    this->LakeSphereIn = NULL;
    this->LakeSphereOut = NULL;
    this->DebugFlowView = EDrawDebugTrace::None;
    this->bFlowInLake = false;
    this->bFlowOutLake = false;
}

