#include "BaseStateComponent.h"

class UGeometryCollection;
class UStaticMesh;

void UBaseStateComponent::SetRepairBaseMesh(UStaticMesh* Mesh) {
}

void UBaseStateComponent::SetDestructibleGeometryCollection(UGeometryCollection* GeometryCollection) {
}

UStaticMesh* UBaseStateComponent::GetRepairBaseMesh() const {
    return NULL;
}

void UBaseStateComponent::AddMarkup(EMarkupType i_Markup, float i_Value) {
}

UBaseStateComponent::UBaseStateComponent() {
    this->MaterialPropertyData = NULL;
    this->bOverrideMaterialProperties = false;
    this->OverrideRepairLocation = NULL;
    this->bImmuneToEverythingExcept = false;
}

