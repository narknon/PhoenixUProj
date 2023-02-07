#include "OnScreenObjectIndicator.h"
#include "Components/WidgetComponent.h"

AOnScreenObjectIndicator::AOnScreenObjectIndicator() {
    this->WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
    this->IndicatorScreenWidgetClass = NULL;
    this->IndicatorScreenWidget = NULL;
    this->OffscreenIndicatorHudSlot = NULL;
    this->bOffscreen = false;
}

