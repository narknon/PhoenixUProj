#include "DecalPointLightComponentBase.h"

class UMaterialInterface;

void UDecalPointLightComponentBase::UpdateDecal() {
}

void UDecalPointLightComponentBase::SetInverseSquaredDecalMaterial(UMaterialInterface* NewInverseSquaredDecalMaterial) {
}

void UDecalPointLightComponentBase::SetFalloffExponentDecalMaterial(UMaterialInterface* NewFalloffExponentDecalMaterial) {
}

UDecalPointLightComponentBase::UDecalPointLightComponentBase() {
    this->DecalMID = NULL;
    this->DecalMIDParent = NULL;
}

