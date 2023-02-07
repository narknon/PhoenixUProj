#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsTimeOnOff.h"
#include "GlobalLightGroupsSchedule.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsSchedule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobalLightGroupsTimeOnOff> ScheduleEntries;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsSchedule();
};

