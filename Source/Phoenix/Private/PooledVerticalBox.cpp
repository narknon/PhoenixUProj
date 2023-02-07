#include "PooledVerticalBox.h"

class UWidget;

void UPooledVerticalBox::SetChildWidgetPool(TArray<UWidget*> ChildWidgets, FMargin Padding) {
}

void UPooledVerticalBox::SetChildActive(UWidget* ChildWidget, bool IsActive) {
}

bool UPooledVerticalBox::IsChildAvailable(UWidget* ChildWidget) {
    return false;
}

bool UPooledVerticalBox::IsChildActive(UWidget* ChildWidget) {
    return false;
}

UWidget* UPooledVerticalBox::GetNextAvailableChild() {
    return NULL;
}

UPooledVerticalBox::UPooledVerticalBox() {
    this->DesiredChildVisibility = ESlateVisibility::Visible;
}

