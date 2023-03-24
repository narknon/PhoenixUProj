#include "RacePlatform.h"
#include "CognitionStimuliSourceComponent.h"



ARacePlatform::ARacePlatform(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CognitionStimuliSource = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("CognitionStimuliSource"));
    this->RaceWidgetClass = NULL;
}

