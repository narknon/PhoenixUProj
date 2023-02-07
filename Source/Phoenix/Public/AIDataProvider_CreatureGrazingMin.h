#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider_QueryParams.h"
#include "AIDataProvider_CreatureGrazingMin.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAIDataProvider_CreatureGrazingMin : public UAIDataProvider_QueryParams {
    GENERATED_BODY()
public:
    UAIDataProvider_CreatureGrazingMin();
};

