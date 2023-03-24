#include "AttachCameraActor.h"
#include "AttachCameraComponent.h"

AAttachCameraActor::AAttachCameraActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AttachCamera = CreateDefaultSubobject<UAttachCameraComponent>(TEXT("AttachCamera"));
}

