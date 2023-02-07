#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsGroupSchedule.h"
#include "GlobalLightGroupsGroupSchedules.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsGroupSchedules {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGlobalLightGroupsGroupSchedule> Schedules;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsGroupSchedules();
};

