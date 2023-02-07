#pragma once
#include "CoreMinimal.h"
#include "TimeSource.h"
#include "TimeSourceVolume.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UTimeSourceVolume : public UTimeSource {
    GENERATED_BODY()
public:
    UTimeSourceVolume();
};

