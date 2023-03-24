#include "WaterVolumeBase.h"

class AActor;
class ACharacter;
class UObjectStateInfo;
class UPrimitiveComponent;
class URagdollControlComponent;

void AWaterVolumeBase::UnDamp(UPrimitiveComponent* Mesh, UObjectStateInfo* ObjectState) {
}

void AWaterVolumeBase::SplashVFX(bool i_Char, EWaterVfx i_vfx, AActor* curActor, UPrimitiveComponent* PrimComp, float waterZ, FVector waterNorm, bool bShallow) {
}

void AWaterVolumeBase::SetupObject(AActor* Actor, UPrimitiveComponent* Mesh, UObjectStateInfo* ObjectState, bool bShouldFloat, bool bSkipIgnore, bool bOverlappingLakeSphere, URagdollControlComponent* RagdollComp) {
}

void AWaterVolumeBase::SetupCharacter(ACharacter* Character, UObjectStateInfo* ObjectState, URagdollControlComponent* RagdollComp, bool bSkipIgnore, bool bOverlappingLakeSphere) {
}

void AWaterVolumeBase::RemoveVFX(EWaterVfx i_vfx, AActor* curActor) {
}

bool AWaterVolumeBase::RemoveActors() {
    return false;
}

void AWaterVolumeBase::OnRagdollRecoveredInWater(URagdollControlComponent* RagdollControlComponent) {
}

void AWaterVolumeBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AWaterVolumeBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

FBoxSphereBounds AWaterVolumeBase::GetBounds(UPrimitiveComponent* Mesh) {
    return FBoxSphereBounds{};
}

void AWaterVolumeBase::ExplosionVFX(AActor* curActor, UPrimitiveComponent* PrimComp, FVector Location, bool inWater, float InForce, float Radius, float Falloff) {
}

void AWaterVolumeBase::Damp(UPrimitiveComponent* Mesh, UObjectStateInfo* ObjectState) {
}

void AWaterVolumeBase::CalcForce(AActor* Actor, UPrimitiveComponent* Mesh, float i_Mass, bool bEmplace, URagdollControlComponent* RagdollComp) {
}

AWaterVolumeBase::AWaterVolumeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->WaterBox = NULL;
    this->DeepCollision = NULL;
    this->ShallowCollision = NULL;
    this->bDisableFunctionality = false;
    this->PhysicsVolumeFluidFriction = 0.35f;
    this->WaterPhysMat = NULL;
    this->PuddlePhysMat = NULL;
    this->WaterHeight = 0.00f;
    this->MinWaterHeight = 0.00f;
    this->ForcePercent = 0.00f;
}

