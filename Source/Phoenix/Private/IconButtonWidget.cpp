#include "IconButtonWidget.h"

class UObject;
class UTexture2D;

void UIconButtonWidget::TryResolveImage(bool bAsyncLoadIfFail, EUIAsyncLoadPriority OptionalPriority) {
}




void UIconButtonWidget::SetImage(const FString& ImageName, bool MatchSize, EUIAsyncLoadPriority OptionalPriority) {
}

void UIconButtonWidget::SetHexBack(const FString& ImageName) {
}

void UIconButtonWidget::SetFactsheetItemType(EFactsheetItemType Type) {
}

void UIconButtonWidget::SetButtonStatus(const FString& StateImage, bool StateImageVisible, const FString& StateHexBack, bool StateEnabled) {
}







void UIconButtonWidget::OnImageLoaded(UTexture2D* LoadedTexture, UObject* CallbackParam) {
}






TEnumAsByte<EFactsheetItemType> UIconButtonWidget::GetFactsheetItemType() {
    return FACTSHEET_ITEM_TYPE_UNKNOWN;
}

FString UIconButtonWidget::GetFactsheetItemName() {
    return TEXT("");
}

FString UIconButtonWidget::GetFactsheetItemDesc() {
    return TEXT("");
}


void UIconButtonWidget::ButtonUnhovered() {
}

void UIconButtonWidget::ButtonReleased() {
}

void UIconButtonWidget::ButtonPressed() {
}

void UIconButtonWidget::ButtonHovered() {
}

void UIconButtonWidget::ButtonClicked() {
}


UIconButtonWidget::UIconButtonWidget() {
    this->IconScale = 1.00f;
    this->IconButtonState = EIconButtonState::BS_Enabled;
    this->TheButton = NULL;
    this->TheImage = NULL;
    this->hexBack = NULL;
    this->LastRequestedMatchSize = false;
}

