#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider_QueryParams.h"
#include "ECreatureDataProviderValueRangeType.h"
#include "AIDataProvider_CreatureExploreRange.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAIDataProvider_CreatureExploreRange : public UAIDataProvider_QueryParams {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureDataProviderValueRangeType RangeType;
    
    UAIDataProvider_CreatureExploreRange();
};

