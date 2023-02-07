#include "ObjectLevitateComponent.h"

UObjectLevitateComponent::UObjectLevitateComponent() {
    this->HoverForce = 40.00f;
    this->TorqueScale = 50.00f;
    this->HoverHeight = 150.00f;
    this->LinearDamping = 1.50f;
    this->AngularDamping = 1.50f;
    this->DefaultLevitateVfx = NULL;
    this->DefaultLevitateSfx = NULL;
    this->bOverrideEffects = false;
    this->LevitateVfx = NULL;
    this->LevitateSfx = NULL;
    this->HoverTargetOffset = NULL;
    this->HoverTargetRotation = NULL;
    this->Owner = NULL;
    this->LevitateMesh = NULL;
    this->SavedHoverHeight = 0.00f;
    this->SavedHoverForce = 0.00f;
    this->SavedMass = 0.00f;
}

