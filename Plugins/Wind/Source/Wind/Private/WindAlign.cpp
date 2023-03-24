#include "WindAlign.h"
#include "WindAlignComponent.h"

AWindAlign::AWindAlign(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Component = CreateDefaultSubobject<UWindAlignComponent>(TEXT("WindAlignComponent0"));
}

