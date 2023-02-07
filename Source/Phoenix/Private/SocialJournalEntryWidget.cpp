#include "SocialJournalEntryWidget.h"


void USocialJournalEntryWidget::InitDetails(const FString& inIconObserverName, const FString& inIconObserverTypeName, const FString& inIconSourceName, int32 InCount) {
}

USocialJournalEntryWidget::USocialJournalEntryWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->Count = NULL;
    this->IconObserver = NULL;
    this->IconObserverType = NULL;
    this->IconSource = NULL;
}

