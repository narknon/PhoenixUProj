#include "NavigationArrow.h"

class UMaterialInstanceDynamic;


void ANavigationArrow::Show() {
}

bool ANavigationArrow::IsListVisible() {
    return false;
}


void ANavigationArrow::Hide() {
}

UMaterialInstanceDynamic* ANavigationArrow::GetMaterial() {
    return NULL;
}

ANavigationArrow::ANavigationArrow() {
    this->PathActivationRadius = 300.00f;
    this->NearFadeDistanceOutterRadius = 300.00f;
    this->NearFadeDistanceInnerRadius = 100.00f;
    this->FarFadeDistanceOutterRadius = 5000.00f;
    this->FarFadeDistanceInnerRadius = 4500.00f;
}

