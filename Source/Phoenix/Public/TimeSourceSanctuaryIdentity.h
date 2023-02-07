#pragma once
#include "CoreMinimal.h"
#include "TimeSourceLocal.h"
#include "TimeSourceSanctuaryIdentity.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UTimeSourceSanctuaryIdentity : public UTimeSourceLocal {
    GENERATED_BODY()
public:
    UTimeSourceSanctuaryIdentity();
};

