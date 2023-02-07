#include "SceneRigCameraStackActor.h"
#include "Components/SkeletalMeshComponent.h"

ASceneRigCameraStackActor::ASceneRigCameraStackActor() {
    this->SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
    this->EyeSocketName = TEXT("cam_socket");
}

