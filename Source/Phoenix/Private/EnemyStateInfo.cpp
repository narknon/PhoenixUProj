#include "EnemyStateInfo.h"

class AActor;

void UEnemyStateInfo::UpdateMass() {
}

void UEnemyStateInfo::SetPullsAggroAmount(float InAmount) {
}

void UEnemyStateInfo::SetPullsAggro(bool bInPullsAggro) {
}

void UEnemyStateInfo::SetInvulnerableToStaticObjects(bool bInInvulnerable) {
}

void UEnemyStateInfo::SetIgnoreActorHitFrom(AActor* IgnoreActor) {
}

void UEnemyStateInfo::RemoveIgnoreActorHitFrom() {
}

bool UEnemyStateInfo::PullsAggro() const {
    return false;
}

float UEnemyStateInfo::GetPullAggroAmount() const {
    return 0.0f;
}

TArray<UClass*> UEnemyStateInfo::GetFriendlyFireTypeList() const {
    return TArray<UClass*>();
}

UEnemyStateInfo::UEnemyStateInfo() {
}

