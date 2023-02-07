#include "UIInteractiveActor.h"
#include "CognitionStimuliSourceComponent.h"


AUIInteractiveActor::AUIInteractiveActor() {
    this->CognitionStimuliSourceComponent = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("CognitionStimuliSource"));
}

