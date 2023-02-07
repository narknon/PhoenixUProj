#include "FinisherSpellTool.h"

class USkinFXComponent;





USkinFXComponent* AFinisherSpellTool::GetSkinFxComponent() {
    return NULL;
}

void AFinisherSpellTool::FinisherFail() {
}

AFinisherSpellTool::AFinisherSpellTool() {
    this->InitialWorldTimeDilation = 1.00f;
    this->InitialPlayerTimeDilation = 1.00f;
    this->FinishWorldTimeDilation = 1.00f;
    this->HitAOEMunitionActor = NULL;
    this->HitAOEMunitionDataAsset = NULL;
    this->DestroyTargetOnDeath = true;
    this->AOEMunitionActor = NULL;
    this->AOEMunitionDataAsset = NULL;
    this->DeathDecalMaterial = NULL;
    this->DeathDecalLifeSpan = 10.00f;
    this->DeathDecalFadeTime = 2.00f;
    this->DeathDecal3D = NULL;
    this->DeathDecal3DRandomOrientation = true;
    this->DeathDecalOnlyOnGround = false;
    this->TargetActor = NULL;
    this->TargetComponent = NULL;
}

