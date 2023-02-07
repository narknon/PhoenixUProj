#include "StoryGraphCondition_Branch.h"

UStoryGraphCondition_Branch::UStoryGraphCondition_Branch() {
    this->IsVisible = NULL;
    this->IsSelectable = NULL;
    this->DisplayTextID = NULL;
    this->DisplayIcon = EStoryGraphBranchIcon::None;
    this->NonSelectableHandling = 0;
}

