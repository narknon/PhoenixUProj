#include "SceneRigCamera.h"
#include "Components/SkeletalMeshComponent.h"

ASceneRigCamera::ASceneRigCamera() {
    this->SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
    this->CameraSocket = TEXT("cam_socket");
}

