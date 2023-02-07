#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsScheduleEntry.h"
#include "GlobalLightGroupsGroupSchedule.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsGroupSchedule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Group;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobalLightGroupsScheduleEntry> Schedule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HermesEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisabled;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsGroupSchedule();
};

