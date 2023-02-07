#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsScheduleEntry.h"
#include "LightComponentSchedule.generated.h"

USTRUCT(BlueprintType)
struct FLightComponentSchedule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobalLightGroupsScheduleEntry> Schedule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HermesEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bToggleChildren: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDisabled: 1;
    
    GLOBALLIGHTGROUPS_API FLightComponentSchedule();
};

