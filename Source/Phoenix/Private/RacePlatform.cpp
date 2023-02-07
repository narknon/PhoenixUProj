#include "RacePlatform.h"
#include "CognitionStimuliSourceComponent.h"



ARacePlatform::ARacePlatform() {
    this->CognitionStimuliSource = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("CognitionStimuliSource"));
    this->RaceWidgetClass = NULL;
}

