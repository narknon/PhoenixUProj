#include "ablClothOptionsTask.h"

UablClothOptionsTask::UablClothOptionsTask() {
    this->bPiecesListIsInclusive = true;
    this->IterationCount = NULL;
    this->MaxIterationCount = NULL;
    this->SubdivisionCount = NULL;
    this->TeleportDistanceThreshold = NULL;
    this->TeleportRotationThreshold = NULL;
    this->ClothBlendWeight = NULL;
    this->ClothMaxDistanceScale = NULL;
    this->EdgeStiffness = NULL;
    this->BendingStiffness = NULL;
    this->AreaStiffness = NULL;
    this->TetherStiffness = NULL;
    this->DampingCoefficient = NULL;
    this->DragCoefficient = NULL;
    this->LiftCoefficient = NULL;
    this->AdditionalWindVelocity = NULL;
    this->GravityScale = NULL;
    this->GravityOverride = NULL;
    this->AnimDriveStiffness = NULL;
    this->AnimDriveDamping = NULL;
    this->WindVelocityScale = NULL;
    this->LinearVelocityScale = NULL;
    this->AngularVelocityScale = NULL;
    this->FictitiousAngularScale = NULL;
}

