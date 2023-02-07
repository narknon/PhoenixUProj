#include "AttachCameraActor.h"
#include "AttachCameraComponent.h"

AAttachCameraActor::AAttachCameraActor() {
    this->AttachCamera = CreateDefaultSubobject<UAttachCameraComponent>(TEXT("AttachCamera"));
}

