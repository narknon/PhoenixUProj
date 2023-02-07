#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "WorldEventCondition.h"
#include "WorldEventCondition_LocationSchedule.generated.h"

UCLASS(Blueprintable)
class UWorldEventCondition_LocationSchedule : public UWorldEventCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo LocationID;
    
    UWorldEventCondition_LocationSchedule();
};

