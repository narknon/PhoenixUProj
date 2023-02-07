#pragma once
#include "CoreMinimal.h"
#include "TimeSourceLocal.h"
#include "TimeSourceNow.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UTimeSourceNow : public UTimeSourceLocal {
    GENERATED_BODY()
public:
    UTimeSourceNow();
};

