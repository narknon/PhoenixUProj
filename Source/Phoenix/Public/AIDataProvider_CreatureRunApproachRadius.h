#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider_QueryParams.h"
#include "AIDataProvider_CreatureRunApproachRadius.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAIDataProvider_CreatureRunApproachRadius : public UAIDataProvider_QueryParams {
    GENERATED_BODY()
public:
    UAIDataProvider_CreatureRunApproachRadius();
};

