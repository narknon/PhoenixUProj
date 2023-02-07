#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsScheduleEntry.h"
#include "GlobalLightGroupsComponentSchedule.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsComponentSchedule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobalLightGroupsScheduleEntry> Schedule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bToggleChildren: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPropagateToParent: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDisabled: 1;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsComponentSchedule();
};

