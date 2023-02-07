#pragma once
#include "CoreMinimal.h"
#include "EMonthsOfTheYear.h"
#include "WorldEventCondition.h"
#include "WorldEventCondition_MonthsOfTheYear.generated.h"

UCLASS(Blueprintable)
class UWorldEventCondition_MonthsOfTheYear : public UWorldEventCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EMonthsOfTheYear>> MonthsToCheck;
    
    UWorldEventCondition_MonthsOfTheYear();
};

