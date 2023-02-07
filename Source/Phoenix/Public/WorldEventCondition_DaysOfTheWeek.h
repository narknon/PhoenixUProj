#pragma once
#include "CoreMinimal.h"
#include "EDaysOfTheWeek.h"
#include "WorldEventCondition.h"
#include "WorldEventCondition_DaysOfTheWeek.generated.h"

UCLASS(Blueprintable)
class UWorldEventCondition_DaysOfTheWeek : public UWorldEventCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EDaysOfTheWeek>> DaysToCheck;
    
    UWorldEventCondition_DaysOfTheWeek();
};

