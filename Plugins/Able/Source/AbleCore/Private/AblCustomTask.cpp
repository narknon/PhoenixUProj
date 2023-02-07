#include "AblCustomTask.h"

class AActor;
class UAblAbilityContext;
class UAblCustomTaskScratchPad;

void UAblCustomTask::OnTaskTickBP_Implementation(const UAblAbilityContext* Context, float DeltaTime) const {
}

void UAblCustomTask::OnTaskStartBP_Implementation(const UAblAbilityContext* Context) const {
}

void UAblCustomTask::OnTaskEndBP_Implementation(const UAblAbilityContext* Context, const EAblAbilityTaskResult Result) const {
}

bool UAblCustomTask::IsSingleFrameBP_Implementation() const {
    return false;
}

bool UAblCustomTask::IsDoneBP_Implementation(const UAblAbilityContext* Context) const {
    return false;
}

EAblAbilityTaskRealm UAblCustomTask::GetTaskRealmBP_Implementation() const {
    return EAblAbilityTaskRealm::Client;
}

FText UAblCustomTask::GetTaskNameBP_Implementation() const {
    return FText::GetEmpty();
}

FText UAblCustomTask::GetTaskDescriptionBP_Implementation() const {
    return FText::GetEmpty();
}

FLinearColor UAblCustomTask::GetTaskColorBP_Implementation() const {
    return FLinearColor{};
}

FText UAblCustomTask::GetTaskCategoryBP_Implementation() const {
    return FText::GetEmpty();
}

UAblCustomTaskScratchPad* UAblCustomTask::GetScratchPad(UAblAbilityContext* Context) const {
    return NULL;
}

FText UAblCustomTask::GetDescriptiveTaskNameBP_Implementation() const {
    return FText::GetEmpty();
}

void UAblCustomTask::GetActorsForTaskBP(const UAblAbilityContext* Context, TArray<AActor*>& OutActorArray) const {
}

UAblCustomTaskScratchPad* UAblCustomTask::CreateScratchPadBP_Implementation(UAblAbilityContext* Context) const {
    return NULL;
}

UAblCustomTask::UAblCustomTask() {
}

