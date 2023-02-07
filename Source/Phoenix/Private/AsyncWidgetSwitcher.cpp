#include "AsyncWidgetSwitcher.h"

class UAsyncLoadWrapper;
class UUserWidget;

void UAsyncWidgetSwitcher::SetParent(UUserWidget* NewParent) {
}

void UAsyncWidgetSwitcher::OnActiveItemLoaded(UAsyncLoadWrapper* Item) {
}

UAsyncWidgetSwitcher::UAsyncWidgetSwitcher() {
    this->ShouldPreloadAll = true;
}

