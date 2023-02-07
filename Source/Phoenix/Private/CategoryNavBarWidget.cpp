#include "CategoryNavBarWidget.h"

class UIconButtonWidget;

void UCategoryNavBarWidget::PrevCategory() {
}




void UCategoryNavBarWidget::OnCategoryButtonUnHover(UIconButtonWidget* Button) {
}

void UCategoryNavBarWidget::OnCategoryButtonHover(UIconButtonWidget* Button) {
}

void UCategoryNavBarWidget::OnCategoryButtonClicked(UIconButtonWidget* Button) {
}

void UCategoryNavBarWidget::NextCategory() {
}

void UCategoryNavBarWidget::InitializeButton(UIconButtonWidget* Button, FText buttonIcon) {
}


FText UCategoryNavBarWidget::GetCurrentCategory() {
    return FText::GetEmpty();
}


void UCategoryNavBarWidget::AddCategory(FText NewCategory) {
}

UCategoryNavBarWidget::UCategoryNavBarWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->CurCategoryIndex = 0;
    this->BackgroundImage = NULL;
}

