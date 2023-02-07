#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider_QueryParams.h"
#include "ECreatureDataProviderValueRangeType.h"
#include "AIDataProvider_CreatureNewHerdLocationRange.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAIDataProvider_CreatureNewHerdLocationRange : public UAIDataProvider_QueryParams {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureDataProviderValueRangeType RangeType;
    
    UAIDataProvider_CreatureNewHerdLocationRange();
};

