#include "NotificationPanelWidget.h"

class UObject;

void UNotificationPanelWidget::RequestCollectionObtainedNotification(FCollectionNotificationData NewItem) {
}

void UNotificationPanelWidget::RequestCollectionKnownNotification(FCollectionNotificationData NewItem) {
}

void UNotificationPanelWidget::RequestChallengeUpdatedNotification(FChallengeNotificationData NewItem) {
}

void UNotificationPanelWidget::RequestChallengeCompleteNotification(FChallengeNotificationData NewItem) {
}

void UNotificationPanelWidget::OnNotificationAborted(const UObject* Caller) {
}

void UNotificationPanelWidget::OnDisplayPickupNotification(const UObject* Caller) {
}

void UNotificationPanelWidget::OnDisplayMoneyNotification(const UObject* Caller) {
}

void UNotificationPanelWidget::OnDisplayCollectionObtainedNotification(const UObject* Caller) {
}

void UNotificationPanelWidget::OnDisplayCollectionKnownNotification(const UObject* Caller) {
}

void UNotificationPanelWidget::OnDisplayChallengeUpdatedNotification(const UObject* Caller) {
}

void UNotificationPanelWidget::OnDisplayChallengeCompleteNotification(const UObject* Caller) {
}

void UNotificationPanelWidget::ItemCollected(FPickupNotificationData NewItem) {
}









UNotificationPanelWidget::UNotificationPanelWidget() {
    this->NotificationsBox = NULL;
    this->IsActiveChallengeUpdateIncrementable = false;
    this->IsActiveMoneyNotificationIncrementable = false;
}

