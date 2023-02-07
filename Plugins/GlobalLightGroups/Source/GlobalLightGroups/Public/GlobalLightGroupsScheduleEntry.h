#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsTimeOnOff.h"
#include "GlobalLightGroupsTimeSpanOnOff.h"
#include "GlobalLightGroupsScheduleEntry.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsScheduleEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsTimeOnOff OnOff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsTimeSpanOnOff State;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsScheduleEntry();
};

