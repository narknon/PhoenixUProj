#include "AISenseConfig_EnemyAITarget.h"
#include "AISense_EnemyAITarget.h"

UAISenseConfig_EnemyAITarget::UAISenseConfig_EnemyAITarget() {
    this->Implementation = UAISense_EnemyAITarget::StaticClass();
    this->EvaluateSource = EPerceptionPointEvaluateSource::Enemy;
    this->bOverrideDistanceRequirement = false;
    this->PerceiveRadius = 6000.00f;
    this->LoseRadius = 7000.00f;
    this->HeightDifference = 100000.00f;
    this->EvaluateInterval = 0.10f;
    this->TargetSenseAsset = NULL;
    this->NPCTargetSenseAsset = NULL;
    this->NonCombatSenseAsset = NULL;
}

