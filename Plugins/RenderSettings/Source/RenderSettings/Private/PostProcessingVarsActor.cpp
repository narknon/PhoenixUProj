#include "PostProcessingVarsActor.h"
#include "PostProcessingVarsComponent.h"

APostProcessingVarsActor::APostProcessingVarsActor() {
    this->Component = CreateDefaultSubobject<UPostProcessingVarsComponent>(TEXT("PostProcessingVarsComponent"));
}

