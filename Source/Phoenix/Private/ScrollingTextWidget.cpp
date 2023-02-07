#include "ScrollingTextWidget.h"

void UScrollingTextWidget::SetTruncationPosition(float Position) {
}

void UScrollingTextWidget::SetTextKey(const FString& Key) {
}

void UScrollingTextWidget::SetText(FText InText) {
}

void UScrollingTextWidget::SetShouldShowEllipsis(bool pShouldShowEllipsis) {
}

void UScrollingTextWidget::SetScrollSpeed(float pScrollSpeed) {
}

void UScrollingTextWidget::SetPhoenixTextOpacity(float InOpacity) {
}

void UScrollingTextWidget::SetPhoenixTextColorAndOpacity(FSlateColor InColorAndOpacity) {
}

void UScrollingTextWidget::SetHorizontalBoxSize(FMargin Size) {
}

void UScrollingTextWidget::SetColorTag(FDataTableRowHandle NewColorTag) {
}

void UScrollingTextWidget::OnUnhovered() {
}

void UScrollingTextWidget::OnHovered() {
}

float UScrollingTextWidget::GetTruncationPosition() {
    return 0.0f;
}

bool UScrollingTextWidget::GetShouldShowEllipsis() {
    return false;
}

float UScrollingTextWidget::GetScrollSpeed() {
    return 0.0f;
}

FText UScrollingTextWidget::GetPhoenixText() {
    return FText::GetEmpty();
}

FMargin UScrollingTextWidget::GetHorizontalBoxSize() {
    return FMargin{};
}

FDataTableRowHandle UScrollingTextWidget::GetColorTag() {
    return FDataTableRowHandle{};
}

UScrollingTextWidget::UScrollingTextWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->ScrollSpeed = 1.00f;
    this->ShouldShowEllipsis = true;
    this->ScrollType = EScrollingWidgetTypes::SCROLLING_WIDGET_TYPE_NONE;
    this->ShouldLoop = true;
    this->TickerScroll = false;
    this->EllipsisText = TEXT("...");
    this->TruncationPosition = 80.00f;
    this->DefaultScrollLimitPad = 30.00f;
    this->TickerWrapPosition = 0.00f;
    this->ScrollMode = EScrollingWidgetMode::SCROLLING_WIDGET_MODE_ON_HOVER;
    this->TextBlock = NULL;
    this->Translatable = true;
    this->ScaleFontSize = true;
    this->MinDesiredWidth = 0.00f;
    this->bWrapWithInvalidationPanel = false;
    this->TextTransformPolicy = ETextTransformPolicy::None;
    this->HorizontalBox = NULL;
    this->ShouldScroll = false;
    this->ScrollOnHover = true;
    this->ScrollDirection = 0.00f;
}

