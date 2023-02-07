#include "SceneAction_Blueprint.h"

class UObject;
class USceneRig;
class UTimeRig_StoryGraph;
class UTimeRig_StoryGraphNode;

void USceneAction_Blueprint::SetBranchID(FName BranchID) const {
}

void USceneAction_Blueprint::SetAutoDurationBP(float Duration) {
}










bool USceneAction_Blueprint::IsProxyRequiredBP_Implementation() const {
    return false;
}

bool USceneAction_Blueprint::IsInstant_Implementation() const {
    return false;
}

bool USceneAction_Blueprint::IsInEditor() const {
    return false;
}

bool USceneAction_Blueprint::IsEnabledBP() const {
    return false;
}

bool USceneAction_Blueprint::HasPostActorTick_Implementation() const {
    return false;
}

bool USceneAction_Blueprint::HasNormalTick_Implementation() const {
    return false;
}


UTimeRig_StoryGraphNode* USceneAction_Blueprint::GetStoryGraphNode(UObject* Caller) const {
    return NULL;
}

UTimeRig_StoryGraph* USceneAction_Blueprint::GetStoryGraph(UObject* Caller) const {
    return NULL;
}

float USceneAction_Blueprint::GetStartTimeBP() const {
    return 0.0f;
}

float USceneAction_Blueprint::GetSortOrderPostActorTick_Implementation() const {
    return 0.0f;
}

float USceneAction_Blueprint::GetSortOrder_Implementation() const {
    return 0.0f;
}

USceneRig* USceneAction_Blueprint::GetSceneRig() const {
    return NULL;
}

float USceneAction_Blueprint::GetIterationLength_Implementation() const {
    return 0.0f;
}

float USceneAction_Blueprint::GetDuration() const {
    return 0.0f;
}

FText USceneAction_Blueprint::GetDisplayName_Implementation() const {
    return FText::GetEmpty();
}

UObject* USceneAction_Blueprint::GetContext() const {
    return NULL;
}

float USceneAction_Blueprint::GetAutoDurationBP_Implementation() const {
    return 0.0f;
}

UObject* USceneAction_Blueprint::GetActionObjectBP() {
    return NULL;
}

FLinearColor USceneAction_Blueprint::GetActionColor_Implementation() const {
    return FLinearColor{};
}

void USceneAction_Blueprint::FinishNow() {
}

void USceneAction_Blueprint::FinishIn(float SecondsFromNow) {
}

bool USceneAction_Blueprint::DevOnly_IsHammerTime() const {
    return false;
}

USceneAction_Blueprint::USceneAction_Blueprint() {
    this->State = NULL;
}

