#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider_QueryParams.h"
#include "ECreatureDataProviderValueRangeType.h"
#include "ECreatureStance.h"
#include "AIDataProvider_CreatureRelaxTime.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAIDataProvider_CreatureRelaxTime : public UAIDataProvider_QueryParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureStance Stance;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureDataProviderValueRangeType RangeType;
    
    UAIDataProvider_CreatureRelaxTime();
};

