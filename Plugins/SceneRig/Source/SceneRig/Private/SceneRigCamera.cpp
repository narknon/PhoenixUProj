#include "SceneRigCamera.h"
#include "Components/SkeletalMeshComponent.h"

ASceneRigCamera::ASceneRigCamera(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
    this->CameraSocket = TEXT("cam_socket");
}

