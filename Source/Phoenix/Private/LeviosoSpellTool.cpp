#include "LeviosoSpellTool.h"

ALeviosoSpellTool::ALeviosoSpellTool() {
    this->MassMax = 100.00f;
    this->LinearDamping = 1.00f;
    this->AngularDamping = 1.00f;
    this->BeingClimbedLinearDamping = 1.00f;
    this->BeingClimbedAngularDamping = 1.00f;
    this->NoSimulatingWhenBeingClimbed = true;
    this->HoverForce = 25.00f;
    this->RagdollHoverForce = 25.00f;
    this->HoverHeight = 150.00f;
    this->MinDiff = 15.00f;
    this->MaxDiff = 75.00f;
    this->TorqueScale = 50.00f;
    this->HoverTargetOffset = NULL;
    this->HoverTargetRotation = NULL;
    this->UpdateHeight = false;
    this->NoSupportDropRate = 50.00f;
    this->SupportTraceLength = 500.00f;
    this->AOEMunition = NULL;
}

