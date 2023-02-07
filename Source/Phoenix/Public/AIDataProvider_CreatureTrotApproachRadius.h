#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider_QueryParams.h"
#include "AIDataProvider_CreatureTrotApproachRadius.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAIDataProvider_CreatureTrotApproachRadius : public UAIDataProvider_QueryParams {
    GENERATED_BODY()
public:
    UAIDataProvider_CreatureTrotApproachRadius();
};

