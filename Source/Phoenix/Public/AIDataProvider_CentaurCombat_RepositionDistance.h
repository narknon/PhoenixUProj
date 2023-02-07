#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider_QueryParams.h"
#include "AIDataProvider_CentaurCombat_RepositionDistance.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAIDataProvider_CentaurCombat_RepositionDistance : public UAIDataProvider_QueryParams {
    GENERATED_BODY()
public:
    UAIDataProvider_CentaurCombat_RepositionDistance();
};

