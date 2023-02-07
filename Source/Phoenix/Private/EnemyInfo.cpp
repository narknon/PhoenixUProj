#include "EnemyInfo.h"

void UEnemyInfo::Show(bool VisibleIn) {
}

void UEnemyInfo::SetName(FName NameIn) {
}

void UEnemyInfo::SetHelthPercentage(float HealthIn) {
}




UEnemyInfo::UEnemyInfo() : UUserWidget(FObjectInitializer::Get()) {
    this->Health = 0.00f;
    this->Visible = true;
}

