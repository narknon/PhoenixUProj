#include "SpiderWeb_HangingBase.h"

void ASpiderWeb_HangingBase::WingardiumStart(bool i_Start) {
}

void ASpiderWeb_HangingBase::WebRetract() {
}

void ASpiderWeb_HangingBase::WakeTick(bool i_Wake) {
}

void ASpiderWeb_HangingBase::StartWebRetract() {
}

void ASpiderWeb_HangingBase::ScaleStart(bool i_Start, bool i_ScaleUp) {
}

void ASpiderWeb_HangingBase::EndWebRetract() {
}

void ASpiderWeb_HangingBase::DescendoHit() {
}

void ASpiderWeb_HangingBase::BreakConnection(bool i_Explode) {
}

void ASpiderWeb_HangingBase::AccioStart(bool i_Start, float i_Time) {
}

void ASpiderWeb_HangingBase::AccioPull() {
}

ASpiderWeb_HangingBase::ASpiderWeb_HangingBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CableLength = 0.00f;
    this->LootChance = 0.50f;
    this->bSpawnObject = false;
    this->bSpawnSpiders = true;
    this->SpiderType = ESpiderTypeEnum::ST_Woodlouse;
    this->SpiderChance = 0.00f;
    this->BaseSpiderNum = 0;
    this->SpiderNumVariance = 0;
    this->SnapParticle = NULL;
    this->ExtraCableLength = 0.00f;
    this->CableLengthTick = 0.00f;
    this->DescendoCount = 0;
    this->bBroken = false;
    this->AnchorComp = NULL;
    this->PosableMeshComp = NULL;
    this->PhysicsConstraintComp = NULL;
    this->SpawnedSack = NULL;
    this->SackMeshComp = NULL;
    this->TargetComp = NULL;
}

