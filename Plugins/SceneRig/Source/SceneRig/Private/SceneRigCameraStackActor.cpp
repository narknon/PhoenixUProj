#include "SceneRigCameraStackActor.h"
#include "Components/SkeletalMeshComponent.h"

ASceneRigCameraStackActor::ASceneRigCameraStackActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
    this->EyeSocketName = TEXT("cam_socket");
}

