#include "ScheduleItemWidget.h"


void UScheduleItemWidget::ScheduleItemUnhovered() {
}

void UScheduleItemWidget::ScheduleItemHovered() {
}


UScheduleItemWidget::UScheduleItemWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->BackgroundScale = 1.00f;
    this->IconName = TEXT("UI_T_Unknown");
    this->StartTime = 0.00f;
    this->EndTime = 0.00f;
    this->ShowActivityText = false;
}

