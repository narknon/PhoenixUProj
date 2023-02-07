#include "SpiderWeb_EggSack.h"

void ASpiderWeb_EggSack::StartAccioTimer(bool i_Start) {
}

void ASpiderWeb_EggSack::SpawnSpiders() {
}




void ASpiderWeb_EggSack::OnBreak(bool i_Explode) {
}

void ASpiderWeb_EggSack::InitializeSack(float i_LootChance, float i_SpiderChance, ESpiderTypeEnum i_SpiderType, int32 i_SpiderBaseNum, int32 i_SpiderNumVariation, bool i_bObjectNotSpiders, const FString& i_ObjectDBID) {
}

void ASpiderWeb_EggSack::ExplodeSack_Implementation() {
}


ASpiderWeb_EggSack::ASpiderWeb_EggSack() {
    this->bBroken = false;
    this->bFrozen = false;
    this->bOnFire = false;
    this->bSpawnObject = false;
    this->LootChance = 0.00f;
    this->SpiderChance = 0.00f;
    this->SpiderType = ESpiderTypeEnum::ST_Woodlouse;
    this->BaseSpiderNum = 0;
    this->SpiderNumVariance = 0;
    this->ExplodeDelay = 4.00f;
    this->ExplosionDamage = 50.00f;
    this->ExplosionRadius = 200.00f;
    this->OnFireExplosionDamage = 100.00f;
    this->OnFireExplosionRadius = 300.00f;
    this->AccioTime = 3.00f;
    this->EnemySpiders = NULL;
}

