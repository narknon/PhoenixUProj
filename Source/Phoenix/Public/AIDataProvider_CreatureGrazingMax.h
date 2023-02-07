#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider_QueryParams.h"
#include "AIDataProvider_CreatureGrazingMax.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAIDataProvider_CreatureGrazingMax : public UAIDataProvider_QueryParams {
    GENERATED_BODY()
public:
    UAIDataProvider_CreatureGrazingMax();
};

