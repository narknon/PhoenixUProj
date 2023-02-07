#include "HerbPlotState.h"

bool UHerbPlotState::IsGrowing() const {
    return false;
}

int32 UHerbPlotState::GetYield() const {
    return 0;
}

float UHerbPlotState::GetRegrowthTimeRatio() const {
    return 0.0f;
}

FName UHerbPlotState::GetPlotID() const {
    return NAME_None;
}

FName UHerbPlotState::GetPlantID() const {
    return NAME_None;
}

bool UHerbPlotState::GetIsInSanctuary() const {
    return false;
}

FTimespan UHerbPlotState::GetGrowthTimeRemaining() const {
    return FTimespan{};
}

EHerbGrowthState UHerbPlotState::GetGrowthState() const {
    return EHerbGrowthState::None;
}

float UHerbPlotState::GetGrowthProgressRatio() const {
    return 0.0f;
}

FName UHerbPlotState::GetFertilizerID() const {
    return NAME_None;
}

UHerbPlotState::UHerbPlotState() {
    this->HerbPlotActor = NULL;
}

