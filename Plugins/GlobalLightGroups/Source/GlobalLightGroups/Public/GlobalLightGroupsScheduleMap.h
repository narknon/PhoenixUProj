#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsSchedule.h"
#include "GlobalLightGroupsScheduleMap.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsScheduleMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGlobalLightGroupsSchedule> Schedules;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsScheduleMap();
};

