#include "WindAlign.h"
#include "WindAlignComponent.h"

AWindAlign::AWindAlign() {
    this->Component = CreateDefaultSubobject<UWindAlignComponent>(TEXT("WindAlignComponent0"));
}

