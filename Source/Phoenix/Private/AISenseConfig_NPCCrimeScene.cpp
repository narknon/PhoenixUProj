#include "AISenseConfig_NPCCrimeScene.h"
#include "AISense_NPCCrimeScene.h"

UAISenseConfig_NPCCrimeScene::UAISenseConfig_NPCCrimeScene() {
    this->Implementation = UAISense_NPCCrimeScene::StaticClass();
    this->SenseAsset = NULL;
    this->PerceiveRadius = 6000.00f;
    this->LoseRadius = 7000.00f;
    this->HeightDifference = 10000.00f;
    this->EvaluateInterval = 0.10f;
}

