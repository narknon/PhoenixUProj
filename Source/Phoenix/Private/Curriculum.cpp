#include "Curriculum.h"

class UCurriculum;

bool UCurriculum::SetCompleteYear_Updated(EDisciplineType Discipline, int32 Year) {
    return false;
}

bool UCurriculum::SetCompleteAllTurnIns_Updated(EDisciplineType Discipline, int32 Year) {
    return false;
}

bool UCurriculum::HasCompletedYear_Updated(EDisciplineType Discipline, int32 Year) {
    return false;
}

void UCurriculum::GivePlayerRewardKnowledge_Updated(EDisciplineType Discipline, int32 Year) {
}

void UCurriculum::GivePlayerRewardItems_Updated(EDisciplineType Discipline, int32 Year) {
}

bool UCurriculum::GetUncompletedTurnIns_Updated(EDisciplineType Discipline, int32 Year, TArray<FCurriculumRequirements_Updated>& UncompletedTurnIns) {
    return false;
}

int32 UCurriculum::GetMaxYear() const {
    return 0;
}

int32 UCurriculum::GetHighestYearCompletedOverall_Updated() {
    return 0;
}

int32 UCurriculum::GetHighestYearCompleted_Updated(EDisciplineType Discipline) {
    return 0;
}

int32 UCurriculum::GetCurrentYear_Updated(EDisciplineType Discipline) {
    return 0;
}

TArray<FCurriculumKnowledgeRequirement> UCurriculum::GetApplicableKnowledgeCards(EDisciplineType Discipline, int32 Year) {
    return TArray<FCurriculumKnowledgeRequirement>();
}

UCurriculum* UCurriculum::Get() {
    return NULL;
}

UCurriculum::UCurriculum() {
}

