#include "ParticleMeshRenderWidget.h"

class UMaterialInstanceDynamic;
class UMaterialInterface;

void UParticleMeshRenderWidget::StopEmitter() {
}

void UParticleMeshRenderWidget::StartEmitter() {
}

void UParticleMeshRenderWidget::SetMaterial(UMaterialInterface* pMaterial) {
}

FLinearColor UParticleMeshRenderWidget::GetColorAndOpacity() const {
    return FLinearColor{};
}

UMaterialInstanceDynamic* UParticleMeshRenderWidget::CreateMaterial(UMaterialInterface* pMaterial) {
    return NULL;
}

UParticleMeshRenderWidget::UParticleMeshRenderWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->ParticleMesh = NULL;
    this->Material = NULL;
    this->ParticleTexture = NULL;
    this->MaterialDynamic = NULL;
    this->MeshAsset = NULL;
}

