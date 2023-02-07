#include "AblConditionalLookupBranchTask.h"

UAblConditionalLookupBranchTask::UAblConditionalLookupBranchTask() {
    this->InteractionArchitectAsset = NULL;
    this->Project = EInteractionProject::Reactions;
    this->bAllowBranchingIntoCurrentAbility = false;
}

