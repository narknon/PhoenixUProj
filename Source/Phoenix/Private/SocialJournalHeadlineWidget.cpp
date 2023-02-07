#include "SocialJournalHeadlineWidget.h"


void USocialJournalHeadlineWidget::InitDetails(FText NewName, const FString& IconName, int32 NewCount) {
}

USocialJournalHeadlineWidget::USocialJournalHeadlineWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->Count = NULL;
    this->Icon = NULL;
    this->Name = NULL;
}

