#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider_QueryParams.h"
#include "AIDataProvider_CreatureGrazingWait.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAIDataProvider_CreatureGrazingWait : public UAIDataProvider_QueryParams {
    GENERATED_BODY()
public:
    UAIDataProvider_CreatureGrazingWait();
};

