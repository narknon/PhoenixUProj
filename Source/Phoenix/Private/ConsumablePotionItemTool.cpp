#include "ConsumablePotionItemTool.h"
#include "Components/StaticMeshComponent.h"
#include "NiagaraComponent.h"
#include "PotionBottlePhysics.h"

void AConsumablePotionItemTool::ThrowPotionBottleTimerExpired() {
}

void AConsumablePotionItemTool::ThrowPotionBottle() {
}

void AConsumablePotionItemTool::DrinkPotion() {
}

AConsumablePotionItemTool::AConsumablePotionItemTool() {
    this->PotionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PotionStaticMesh"));
    this->LiquidParticleSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("LiquidParticleSystem"));
    this->LiquidDrainTime = 0.25f;
    this->PotionConsumeVFX = NULL;
    this->NiagaraPotionConsumeVFX = NULL;
    this->VFXBoneAttachmentName = TEXT("Spine3");
    this->PotionConsumeNiagaraComponent = NULL;
    this->PotionBottlePhysicsClass = APotionBottlePhysics::StaticClass();
}

