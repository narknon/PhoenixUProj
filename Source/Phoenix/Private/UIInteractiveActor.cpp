#include "UIInteractiveActor.h"
#include "CognitionStimuliSourceComponent.h"


AUIInteractiveActor::AUIInteractiveActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CognitionStimuliSourceComponent = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("CognitionStimuliSource"));
}

