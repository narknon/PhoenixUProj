#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TimeSource.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UTimeSource : public UObject {
    GENERATED_BODY()
public:
    UTimeSource();
};

