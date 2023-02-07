#include "IconNoteWidget.h"

void UIconNoteWidget::SetDetails(const FString& IconName, int32 Quantity, FText DescriptionOverride, const bool bAlreadyTranslated) {
}


UIconNoteWidget::UIconNoteWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->NoteImage = NULL;
    this->NoteLabel = NULL;
}

