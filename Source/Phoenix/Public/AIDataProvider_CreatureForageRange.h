#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider_QueryParams.h"
#include "ECreatureDataProviderValueRangeType.h"
#include "AIDataProvider_CreatureForageRange.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAIDataProvider_CreatureForageRange : public UAIDataProvider_QueryParams {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureDataProviderValueRangeType RangeType;
    
    UAIDataProvider_CreatureForageRange();
};

