#include "CallOutComponent.h"

class UObject;
class UPhoenixUserWidget;

void UCallOutComponent::UpdateCallOutUI_Implementation() {
}

void UCallOutComponent::ShowWidgetForThisCallout_Implementation() {
}

void UCallOutComponent::OnOutroEnded(UPhoenixUserWidget* BaseItem, int32 OutroType) {
}

void UCallOutComponent::HideWidgetForThisCallout_Implementation() {
}

void UCallOutComponent::AwareStateInfoHandler(const UObject* i_caller, const FAwareStateInfo& AwareStateInfo) {
}

void UCallOutComponent::AttackThreatDataHandler(const UObject* i_caller, const FEnemy_AttackThreatData& AttackThreatData) {
}

UCallOutComponent::UCallOutComponent() {
    this->OnScreen = false;
    this->targeted = false;
    this->EnemytoPlayer = false;
    this->BeaconSize = 50.00f;
    this->IsBeaconTracked = false;
    this->PostAlertKeepActiveTime = 0.20f;
    this->EnemyAIComp = NULL;
    this->MyScheduledEntity = NULL;
    this->OffScreenWidget = NULL;
    this->OffScreenArrow = NULL;
    this->OffscreenWidgetHudSlot = NULL;
}

