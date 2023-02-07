#include "MissionLogWidget.h"

bool UMissionLogWidget::TrackNewObjective(const FString& ObjectiveName) {
    return false;
}

bool UMissionLogWidget::MissionHasBeaconOnMap(FName MissionID) const {
    return false;
}

bool UMissionLogWidget::HasBeenInitialized() const {
    return false;
}

bool UMissionLogWidget::GetTrackedMissionId(FName& MissionID) const {
    return false;
}

bool UMissionLogWidget::GetTrackedMissionData(FMissionLogData& MissionData) const {
    return false;
}

TArray<FMissionLogData> UMissionLogWidget::GetMissionLogData(int32& OutTrackedMissionIndex) {
    return TArray<FMissionLogData>();
}

bool UMissionLogWidget::GetMapIconAndGlint(FName MissionID, FString& Icon, FString& Glint, FLinearColor& IconColor) const {
    return false;
}

bool UMissionLogWidget::GetLighthouseGoalInfo(FName& LighthouseGoalID, TArray<FName>& LighthouseObjectives, TArray<bool>& ObjectiveUnlockedStates, TArray<bool>& ObjectiveCompleteStates) const {
    return false;
}

bool UMissionLogWidget::GetActiveObjectiveTrackableStates(TArray<bool>& TrackableStates, FString& TrackedObjective) const {
    return false;
}

bool UMissionLogWidget::CanAbandonMission(FName MissionID) {
    return false;
}

UMissionLogWidget::UMissionLogWidget() {
}

