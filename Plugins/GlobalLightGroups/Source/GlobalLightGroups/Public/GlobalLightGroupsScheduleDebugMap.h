#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsScheduleDebugMapEntry.h"
#include "GlobalLightGroupsScheduleDebugMap.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsScheduleDebugMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobalLightGroupsScheduleDebugMapEntry> Schedules;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsScheduleDebugMap();
};

