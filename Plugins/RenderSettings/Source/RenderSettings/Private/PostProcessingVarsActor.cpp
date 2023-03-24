#include "PostProcessingVarsActor.h"
#include "PostProcessingVarsComponent.h"

APostProcessingVarsActor::APostProcessingVarsActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Component = CreateDefaultSubobject<UPostProcessingVarsComponent>(TEXT("PostProcessingVarsComponent"));
}

