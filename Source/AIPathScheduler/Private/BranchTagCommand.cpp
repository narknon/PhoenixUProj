#include "BranchTagCommand.h"

FBranchTagCommand::FBranchTagCommand() {
    this->UUID_BranchTo = 0;
    this->FromPathPointIndex = 0;
    this->ToPathPointIndex = 0;
    this->Probability = 0.00f;
    this->ForwardToBranchDirection = ETrafficFlow::Forward;
    this->BackwardToBranchDirection = ETrafficFlow::Forward;
}

