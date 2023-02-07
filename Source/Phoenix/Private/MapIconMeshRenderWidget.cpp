#include "MapIconMeshRenderWidget.h"

class UBeaconInfo;
class UMapIconInstance;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UObject;
class UTexture2D;

void UMapIconMeshRenderWidget::SetTexture(UTexture2D* Texture) {
}

void UMapIconMeshRenderWidget::SetOutlineTexture(UTexture2D* Texture) {
}

void UMapIconMeshRenderWidget::SetName(const FString& pName) {
}

void UMapIconMeshRenderWidget::SetMaterial(UMaterialInterface* pMaterial) {
}

void UMapIconMeshRenderWidget::SetLayer3Texture(UTexture2D* Texture) {
}

void UMapIconMeshRenderWidget::SetLayer2Texture(UTexture2D* Texture) {
}

void UMapIconMeshRenderWidget::SetCurrentTextureName(const FString& pTextureName) {
}

void UMapIconMeshRenderWidget::SetCurrentBeaconState(EBeaconState pCurrentBeaconState) {
}

bool UMapIconMeshRenderWidget::RemoveIcon(UMapIconInstance* Icon) {
    return false;
}

void UMapIconMeshRenderWidget::IconTextureCallback(UTexture2D* Texture, UObject* Param) {
}

FString UMapIconMeshRenderWidget::GetWidgetName() {
    return TEXT("");
}

UMaterialInstanceDynamic* UMapIconMeshRenderWidget::GetMaterialDynamic() {
    return NULL;
}

UMaterialInterface* UMapIconMeshRenderWidget::GetMaterial() {
    return NULL;
}

FString UMapIconMeshRenderWidget::GetCurrentTextureName() {
    return TEXT("");
}

EBeaconState UMapIconMeshRenderWidget::GetCurrentBeaconState() {
    return EBeaconState::BEACONSTATE_NONE;
}

FLinearColor UMapIconMeshRenderWidget::GetColorAndOpacity() const {
    return FLinearColor{};
}

UMaterialInstanceDynamic* UMapIconMeshRenderWidget::CreateMaterial(UMaterialInterface* pMaterial) {
    return NULL;
}

bool UMapIconMeshRenderWidget::CONTAINS(UMapIconInstance* Icon) {
    return false;
}

void UMapIconMeshRenderWidget::ClearIcons() {
}

void UMapIconMeshRenderWidget::ClearBeaconList() {
}

void UMapIconMeshRenderWidget::AddIconToList(UMapIconInstance* MapIconInstance) {
}

UMapIconInstance* UMapIconMeshRenderWidget::AddIcon(UBeaconInfo* Beacon, FVector2D Position, float Scale, float flags, FLinearColor Color) {
    return NULL;
}

void UMapIconMeshRenderWidget::AddBeaconToList(UBeaconInfo* pBeaconInfo) {
}

UMapIconMeshRenderWidget::UMapIconMeshRenderWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->Material = NULL;
    this->NumIcons = 0;
    this->MaterialDynamic = NULL;
    this->MeshAsset = NULL;
}

