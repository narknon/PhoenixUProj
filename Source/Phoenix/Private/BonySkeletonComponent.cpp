#include "BonySkeletonComponent.h"

bool UBonySkeletonComponent::Initialize(FName ProfileName) {
    return false;
}

void UBonySkeletonComponent::Abort() {
}

UBonySkeletonComponent::UBonySkeletonComponent() {
    this->SkeletonMesh = NULL;
    this->SkeletonPhysiscsAssetOveride = NULL;
    this->SkeletonMeshComponent = NULL;
    this->SkinFXComponent = NULL;
    this->Age = 0.00f;
    this->bInitialized = false;
}

