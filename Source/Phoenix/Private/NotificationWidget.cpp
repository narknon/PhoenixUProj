#include "NotificationWidget.h"



void UNotificationWidget::InitDetails(const FString& NewItemName, FName NewVariation, const FString& DisplayName, bool bIsHeaderTranslatable, int32 NewItemCount, const FString& NewIconName, bool bSpecialCollection) {
}


UNotificationWidget::UNotificationWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->Subheader = NULL;
    this->Icon = NULL;
    this->Header = NULL;
    this->ItemCount = 0;
    this->LifeTime = 8.00f;
}

