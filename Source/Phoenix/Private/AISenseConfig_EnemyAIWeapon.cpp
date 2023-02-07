#include "AISenseConfig_EnemyAIWeapon.h"
#include "AISense_EnemyAIWeapon.h"

UAISenseConfig_EnemyAIWeapon::UAISenseConfig_EnemyAIWeapon() {
    this->Implementation = UAISense_EnemyAIWeapon::StaticClass();
    this->bOverrideDistanceRequirement = false;
    this->PerceiveRadius = 3000.00f;
}

