#include "AblLookupBranchTask.h"

UAblLookupBranchTask::UAblLookupBranchTask() {
    this->InteractionArchitectAsset = NULL;
    this->Project = EInteractionProject::Reactions;
    this->bMustPassAllConditions = true;
    this->bCopyTargetsOnBranch = false;
    this->bOverrideTransitionBlend = true;
    this->bClampBlendOutTime = true;
}

