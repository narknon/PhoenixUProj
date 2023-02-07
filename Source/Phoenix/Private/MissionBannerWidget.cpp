#include "MissionBannerWidget.h"






void UMissionBannerWidget::BeginOrEndPlay(const bool endPlay) {
}

void UMissionBannerWidget::BannerComplete(const ENotificationCategory Category) {
}

UMissionBannerWidget::UMissionBannerWidget() {
    this->StepUpdateInProgress = false;
    this->MissionStepsShowing = false;
    this->WaypointShowing = false;
}

